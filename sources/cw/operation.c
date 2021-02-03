/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:15:04 by esnowpea          #+#    #+#             */
/*   Updated: 2021/02/03 13:48:55 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "asm_op.h"

uint8_t		vm_checkout(t_vm *vm)
{
	t_list	*tmp;
	t_list	*del;

	tmp = vm->carriages;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		if (((vm->number_cycle - ((t_carriage*)del->content)->number_last_live)
		>= (uint32_t)vm->cycles_to_die) || (vm->cycles_to_die <= 0))
			ft_lstpdelone(&vm->carriages, del);
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

void		cr_operation_make(t_carriage *car, t_vm *vm)
{
	g_ops[car->operation - 1].fun(car, vm);
	if (car->operation != 0x09)
		car->position = (car->position + car->args_len) % MEM_SIZE;
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
		vm_survey_carriages(vm);
		vm->number_cycle++;
		current = 1;
		while (current < (uint32_t)vm->cycles_to_die && vm->cycles_to_die > 0)
		{
			ft_visualiser(vm);
			vm_survey_carriages(vm);
			current++;
			vm->number_cycle++;
			if ((vm->flag.d && vm->flag.d == vm->number_cycle)\
			|| (vm->flag.dump && vm->flag.dump == vm->number_cycle))
			{
				vm_print_arena(vm);
				exit(0);
			}
		}
		vm->number_checks++;
	}
	return (vm->last_live_player);
}
