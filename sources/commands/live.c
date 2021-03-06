/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:37:39 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 12:37:39 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

void		live(t_carriage *car, t_vm *vm)
{
	vm->number_live++;
	car->number_last_live = vm->number_cycle;
	if (pl_find(vm->players, -ft_bytetoint(car->args[0].data, DIR_SIZE)))
		vm->last_live_player = pl_find(vm->players,
			-ft_bytetoint(car->args[0].data, DIR_SIZE));
}
