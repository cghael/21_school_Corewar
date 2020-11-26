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

void		ft_lstpdelone(t_list **alst, t_list *del) //TODO add to libft
{
	t_list	*tmp;
	if (!alst || !(*alst) || !del)
		return ;
	if (*alst == del)
	{
		*alst = (*alst)->next;
		free(del);
		return ;
	}
	else
	{
		tmp = *alst;
		while (tmp->next && tmp->next != del)
			tmp = tmp->next;
		tmp->next = del->next;
		free(del);
		return ;
	}
}

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
	if (arg == 1)
		return (1);
	if (arg == 2)
		return (dir);
	if (arg == 4)
		return (2);
	return (0);
}

uint32_t	check_oper_args(uint8_t oper, uint8_t args)
{
	uint32_t		sum;
	uint8_t			arg[3];

	arg[0] = (args >> 6) | 3 == 3 ? 4 : (args >> 6) | 3;
	arg[1] = (args >> 4) | 3 == 3 ? 4 : (args >> 4) | 3;
	arg[2] = (args >> 2) | 3 == 3 ? 4 : (args >> 2) | 3;
	if ((g_ops[oper - 1].n_args == 3 &&
		(g_ops[oper - 1].args[0] | arg[0]) &&
		(g_ops[oper - 1].args[1] | arg[1]) &&
		(g_ops[oper - 1].args[2] | arg[2])) ||
		(g_ops[oper - 1].n_args == 2 &&
		(g_ops[oper - 1].args[0] | arg[0]) &&
		(g_ops[oper - 1].args[1] | arg[1])) ||
		(g_ops[oper - 1].n_args == 1 &&
		(g_ops[oper - 1].args[0] | arg[0])))
		return (0);
	sum = 1 + g_ops[oper - 1].is_args_type +
			find_size_arg(arg[0], 4 - 2 * g_ops[oper - 1].is_small_dir);
	if (g_ops[oper - 1].n_args > 1)
		sum += find_size_arg(arg[1], 4 - 2 * g_ops[oper - 1].is_small_dir);
	if (g_ops[oper - 1].n_args > 2)
		sum += find_size_arg(arg[2], 4 - 2 * g_ops[oper - 1].is_small_dir);
	return (sum);
}

t_player	*pl_find(t_list *players, uint32_t n)
{
	t_list	*tmp;

	tmp = players;
	while (tmp)
	{
		if (((t_player*)tmp->content)->number == n)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int32_t		ucarrtoint(uint8_t const arg[], uint8_t len)
{
	int8_t		i;
	int32_t		sum;
	uint32_t	k;

	i = 0;
	sum = 0;
	k = 1;
	while (i < len)
	{
		sum += arg[i++] * k;
		k *= 256;
	}
	return (sum);
}

void		cr_operation_make(t_carriage *car, t_vm *vm)
{
	uint8_t		arg[DIR_SIZE];

	if (car->operation == 0x01)
	{
		car->number_last_live = vm->number_cycle;
		ft_memcpy(&arg, &vm->arena[car->position], 4);
		if (pl_find(vm->players, -ucarrtoint(arg, DIR_SIZE)))
			vm->last_live_player =
					pl_find(vm->players, -ucarrtoint(arg, DIR_SIZE));
	}
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
				vm->arena[(car->position + 1) % MEM_SIZE]))
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
			vm_print_arena(vm);
			current++;
			vm->number_cycle++;
		}
		vm->number_checks++;
	}
	return (vm->last_live_player);
}