/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 22:15:48 by ksemele           #+#    #+#             */
/*   Updated: 2021/02/05 22:15:49 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <ncurses.h>

static void		vi_cycle(t_vm *vm)
{
	uint32_t	current;

	current = 0;
	vi_handle_buttons(vm);
	if (vm->vi->is_running)
	{
		while (vm->carriages)
		{
			vm_survey_carriages(vm);
			current++;
			vm->number_cycle++;
			if (vm->cycles_to_die <= 0 ||
				current == (uint32_t)vm->cycles_to_die)
			{
				vm->number_checks++;
				current = 0;
				vm_checkout(vm);
			}
		}
	}
}

t_player		*vi_operation(t_vm *vm)
{
	ft_visualiser(vm);
	if (vm->flag.v)
		ft_vi_print_arena(vm);
	while ((vm->vi->button = getch()) != ESC)
		vi_cycle(vm);
	if (vm->flag.v)
		ft_vi_print_arena(vm);
	endwin();
	return (vm->last_live_player);
}
