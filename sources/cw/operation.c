/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:15:04 by esnowpea          #+#    #+#             */
/*   Updated: 2020/11/19 17:16:54 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "asm_op.h"

uint8_t		vm_checkout(t_vm *vm)
{
	t_list	*tmp;

	tmp = vm->carriages;
	while (tmp)
	{
		if (vm->number_cycle - ((t_carriage*)tmp->content)->number_last_live
		>= vm->cycles_to_die || vm->cycles_to_die <= 0)
			ft_lstpdelone(&vm->carriages, tmp);
		tmp = tmp->next;
	}
	if (vm->number_live >= NBR_LIVE || vm->number_checks >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->number_checks = 0;
	}
	if (vm->carriages)
		return (1);
	else
		return (0);
}

uint8_t		find_size_arg(uint8_t arg, uint8_t dir)
{
	if (arg == REG)
		return (1);
	if (arg == DIR)
		return (dir);
	if (arg == IND)
		return (2);
	return (0);
}

uint32_t	len_oper_args(uint8_t oper, uint8_t args)
{
	uint32_t		sum;
	uint8_t			arg[3];
	t_op			op;

	op = g_ops[oper - 1];
	arg[0] = ((args >> 6) & 3) == 3 ? IND : (args >> 6) & 3;
	arg[1] = ((args >> 4) & 3) == 3 ? IND : (args >> 4) & 3;
	arg[2] = ((args >> 2) & 3) == 3 ? IND : (args >> 2) & 3;
	if (op.is_args_type)
	{
		sum = 2 + find_size_arg(arg[0], 4 - 2 * op.is_small_dir);
		if (op.n_args > 1)
			sum += find_size_arg(arg[1], 4 - 2 * op.is_small_dir);
		if (op.n_args > 2)
			sum += find_size_arg(arg[2], 4 - 2 * op.is_small_dir);
	}
	else
		sum = 1 + 4 - 2 * op.is_small_dir;
	return (sum);
}

uint32_t	check_oper_args(uint8_t oper, uint8_t args)
{
	uint8_t			arg[3];
	t_op			op;

	op = g_ops[oper - 1];
	arg[0] = ((args >> 6) & 3) == 3 ? IND : (args >> 6) & 3;
	arg[1] = ((args >> 4) & 3) == 3 ? IND : (args >> 4) & 3;
	arg[2] = ((args >> 2) & 3) == 3 ? IND : (args >> 2) & 3;
	if (!op.is_args_type ||
		(op.n_args == 3 && (op.args[0] & arg[0]) && (op.args[1] & arg[1]) &&
		(op.args[2] & arg[2])) ||
		(op.n_args == 2 && (op.args[0] & arg[0]) && (op.args[1] & arg[1])) ||
		(op.n_args == 1 && (op.args[0] & arg[0])))
		return (0);
	return (len_oper_args(oper, args));
}

uint8_t		check_reg_number(t_carriage *car, t_vm *vm)
{
	uint8_t			arg[3];
	uint8_t			args;
	t_op			op;

	op = g_ops[car->operation - 1];
	if (!op.is_args_type)
		return (1);
	args = vm->arena[(car->position + 1) % MEM_SIZE];
	arg[0] = ((args >> 6) & 3) == 3 ? IND : (args >> 6) & 3;
	arg[1] = ((args >> 4) & 3) == 3 ? IND : (args >> 4) & 3;
	arg[2] = ((args >> 2) & 3) == 3 ? IND : (args >> 2) & 3;
	arg[0] = find_size_arg(arg[0], 4 - 2 * op.is_small_dir);
	arg[1] = find_size_arg(arg[1], 4 - 2 * op.is_small_dir);
	arg[2] = find_size_arg(arg[2], 4 - 2 * op.is_small_dir);
	if (arg[0] == REG && (vm->arena[car->position + 2] >= REG_NUMBER ||
						vm->arena[car->position + 2] < 1))
		return (0);
	if (arg[1] == REG && (vm->arena[car->position + 1 + arg[0]] >= REG_NUMBER ||
		vm->arena[car->position + 1 + arg[0]] < 1))
		return (0);
	if (arg[2] == REG && (vm->arena[car->position + 1 + arg[0] + arg[1]]
		>= REG_NUMBER || vm->arena[car->position + 1 + arg[0] + arg[1]] < 1))
		return (0);
	return (1);
}

void		cr_operation_make(t_carriage *car, t_vm *vm)
{
	if (car->operation == 0x01)
		live(car, vm);
	else if (car->operation == 0x02)
		ld(car, vm);
	car->position += len_oper_args(car->operation,
					vm->arena[(car->position + 1) % MEM_SIZE]);
}

void		cr_operation(t_carriage *car, t_vm *vm)
{
	if (car->waiting_moves == 0)
	{
		car->operation = vm->arena[car->position];
		if (car->operation >= 0x01 && car->operation <= 0x10)
			car->waiting_moves = g_ops[car->operation - 1].cycles;
	}
	if (car->waiting_moves > 0)
		car->waiting_moves--;
	if (car->waiting_moves == 0)
	{
		if (car->operation < 0x01 || car->operation > 0x10)
			car->position = (car->position + 1) % MEM_SIZE;
		else if (check_oper_args(car->operation,
				vm->arena[(car->position + 1) % MEM_SIZE]) ||
				!check_reg_number(car, vm))
			car->position = (car->position + check_oper_args(car->operation,
				vm->arena[(car->position + 1) % MEM_SIZE])) % MEM_SIZE;
		else
			cr_operation_make(car, vm);
		car->waiting_moves = 0;
	}
}

void		vm_survey_carriages(t_vm *vm)
{
	t_list	*tmp;

	tmp = vm->carriages;
	while (tmp)
	{
		cr_operation(tmp->content, vm);
		tmp = tmp->next;
	}
}

t_player	*vm_operation(t_vm *vm)
{
	uint32_t	current;

	while (vm_checkout(vm))
	{
		current = 0;
		while (current < vm->cycles_to_die)
		{
			vm_survey_carriages(vm);
			current++;
			vm->number_cycle++;
		}
		vm->number_checks++;
		vm_print_arena(vm);
	}
	return (vm->last_live_player);
}