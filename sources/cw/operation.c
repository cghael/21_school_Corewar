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
	vm->number_live = 0;
	if (vm->carriages)
		return (1);
	else
		return (0);
}

void 		set_arena(uint8_t *arena, int32_t pos, const uint8_t *data,
				 uint32_t len)
{
	uint32_t	i;

	i = 0;
	while (pos < 0)
		pos += MEM_SIZE;
	while (i < len)
	{
		arena[(pos + i) % MEM_SIZE] = data[i];
		i++;
	}
}

uint8_t 	*get_array(uint8_t *array, int32_t pos)
{
	while (pos < 0)
		pos += MEM_SIZE;
	return (&array[pos % MEM_SIZE]);
}

uint8_t		*get_dir(uint8_t n, t_carriage *car, t_vm *vm)
{
	return (get_array(vm->arena, car->args[n].pos));
}

uint8_t		*get_reg(uint8_t n, t_carriage *car, t_vm *vm)
{
	uint8_t		reg_nb;

	reg_nb = *get_array(vm->arena, car->args[n].pos);
	if (reg_nb < 1 || reg_nb > REG_NUMBER)
		return (0);
	return (car->reg[reg_nb - 1]);
}

uint8_t		*get_ind(uint8_t n, t_carriage *car, t_vm *vm)
{
	int32_t		ind;

	ind = ft_bitetoint(get_array(vm->arena, car->args[n].pos), IND_SIZE)
			% IDX_MOD;
	return (get_array(vm->arena, car->position + ind));
}

uint8_t		*get_data(uint8_t n, t_carriage *car, t_vm *vm)
{
	if (car->args[n].type == T_DIR)
		return (get_dir(n, car, vm));
	else if (car->args[n].type == T_REG)
		return (get_reg(n, car, vm));
	else
		return (get_ind(n, car, vm));
}

void		cr_set_args_type(t_carriage *car, t_vm *vm)
{
	uint8_t		arg_code;
	uint8_t		i;

	arg_code = vm->arena[(car->position + 1) % MEM_SIZE];
	i = 0;
	if (g_ops[car->operation - 1].is_args_type)
		while (i < g_ops[car->operation - 1].n_args)
		{
			car->args[i].type = ((arg_code >> (6 - i * 2)) & 3) == IND_CODE ?
							   T_IND : ((arg_code >> (6 - i * 2)) & 3);
			car->args[i].len = find_len_arg(car->args[i].type, car->operation);
			i++;
		}
	else
	{
		car->args[0].type = g_ops[car->operation - 1].args[0];
		car->args[0].len = find_len_arg(car->args[0].type, car->operation);
	}
}

void		cr_set_args_pos(t_carriage *car, t_vm *vm)
{
	uint8_t		i;
	uint32_t	pos;

	i = 0;
	pos = (car->position + 2) % MEM_SIZE;
	if (g_ops[car->operation - 1].is_args_type)
		while (i < g_ops[car->operation - 1].n_args)
		{
			car->args[i].pos = pos;
			pos += car->args[i].len;
			pos %= MEM_SIZE;
			i++;
		}
	else
		car->args[0].pos = (car->position + 1) % MEM_SIZE;
}

void		cr_set_args_data(t_carriage *car, t_vm *vm)
{
	uint8_t		i;

	i = 0;
	while (i < g_ops[car->operation - 1].n_args)
	{
		car->args[i].data = get_data(i, car, vm);
		i++;
	}
}

void		cr_set_args_null(t_carriage *car, t_vm *vm)
{
	uint8_t		i;

	i = 0;
	while (i < 3)
	{
		car->args[i].data = 0;
		car->args[i].type = 0;
		car->args[i].pos = 0;
		car->args[i].len = 0;
		i++;
	}
}

uint8_t		cr_set_args(t_carriage *car, t_vm *vm)
{
	uint8_t		i;

	cr_set_args_null(car, vm);
	cr_set_args_type(car, vm);
	cr_set_args_pos(car, vm);
	cr_set_args_data(car, vm);
	i = 0;
	while (i < g_ops[car->operation - 1].n_args)
	{
		if (!car->args[i].data)
			return (0);
		i++;
	}
	return (1);
}

uint8_t		find_len_arg(uint8_t arg, uint8_t operation)
{
	if (arg == T_REG)
		return (1);
	if (arg == T_DIR)
		return (4 - 2 * g_ops[operation - 1].is_small_dir);
	if (arg == T_IND)
		return (2);
	return (0);
}

uint32_t	len_args(t_carriage *car, t_vm *vm)
{
	uint32_t		sum;
	t_op			op;
	uint8_t			arg_code;

	arg_code = vm->arena[(car->position + 1) % MEM_SIZE];
	op = g_ops[car->operation - 1];
	if (op.is_args_type)
	{
		sum = 2 + find_len_arg(((arg_code >> 6) & 3) == IND_CODE ?
				T_IND : ((arg_code >> 6) & 3), car->operation);
		if (op.n_args > 1)
			sum += find_len_arg(((arg_code >> 4) & 3) == IND_CODE ?
					T_IND : ((arg_code >> 4) & 3), car->operation);
		if (op.n_args > 2)
			sum += find_len_arg(((arg_code >> 2) & 3) == IND_CODE ?
					T_IND : ((arg_code >> 2) & 3), car->operation);
	}
	else
		sum = 1 + 4 - 2 * op.is_small_dir;
	return (sum);
}

uint32_t	check_args(t_carriage *car, t_vm *vm)
{
	t_op			op;
	uint8_t			oper;
	uint8_t			byte;

	oper = car->operation;
	byte = vm->arena[(car->position + 1) % MEM_SIZE];
	op = g_ops[oper - 1];
	if (!op.is_args_type ||
		(op.n_args == 3 && (op.args[0] &
		(((byte >> 6) & 3) == IND_CODE ? T_IND : ((byte >> 6) & 3)) &&
		(op.args[1] &
		(((byte >> 4) & 3) == IND_CODE ? T_IND : ((byte >> 4) & 3))) &&
		(op.args[2] &
		(((byte >> 2) & 3) == IND_CODE ? T_IND : ((byte >> 2) & 3)))) ||
		(op.n_args == 2 && (op.args[0] &
		(((byte >> 6) & 3) == IND_CODE ? T_IND : ((byte >> 6) & 3))) &&
		(op.args[1] &
		(((byte >> 4) & 3) == IND_CODE ? T_IND : ((byte >> 4) & 3)))) ||
		(op.n_args == 1 && (op.args[0] &
		(((byte >> 6) & 3) == IND_CODE ? T_IND : ((byte >> 6) & 3))))))
		return (1);
	return (0);
}

void		cr_operation_make(t_carriage *car, t_vm *vm)
{
	if (car->operation == 0x01)
		live(car, vm);
	else if (car->operation == 0x02)
		ld(car, vm);
	else if (car->operation == 0x03)
		st(car,vm);
	else if (car->operation == 0x09)
		zjmp(car,vm);
	else if (car->operation == 0x0a)
		ldi(car,vm);
	else if (car->operation == 0x0b)
		sti(car,vm);
	if (car->operation != 0x09)
		car->position = (car->position + len_args(car, vm)) % MEM_SIZE;
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
		else if (check_args(car, vm) && cr_set_args(car, vm))
			cr_operation_make(car, vm);
		else
			car->position = (car->position + len_args(car, vm)) % MEM_SIZE;
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
	}
	vm_print_arena(vm);
	return (vm->last_live_player);
}