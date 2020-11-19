/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:10:52 by esnowpea          #+#    #+#             */
/*   Updated: 2020/11/19 17:53:36 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list		*vm_carriages_init(t_list *players)
{
	t_list	*carrriages;

	carrriages = NULL;
	//TODO initialization carriages
	return (carrriages);
}

t_vm		*vm_init(int ac, char **av)
{
	t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		return (NULL);
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->players = parsing_input(ac, av);
	vm->last_live_player = pl_max_number(vm->players); //TODO write fun player with max number
	vm->carriages = vm_carriages_init(vm->players);
	return (vm);
}