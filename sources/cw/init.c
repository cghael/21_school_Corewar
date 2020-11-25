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

t_list	*ft_lstpnew(void *content) //TODO add to libft
{
    t_list	*lstnew;

    if (!(lstnew = (t_list*)ft_memalloc(sizeof(t_list))))
        return (NULL);
    lstnew->content = content;
    return (lstnew);
}

t_list		*vm_init_players(int ac, char **av)
{
    t_list		*players;

    players = NULL;
    //TODO parsing and add players to list with number
    return (players);
}

t_carriage  *cr_init(t_player *player, unsigned int nb)
{
    t_carriage  *carriage;

    if (!(carriage = ft_memalloc(sizeof(t_carriage))))
        return (0);
    carriage->number = nb;
    carriage->reg[0] = -player->number;
    carriage->player = player;
    return (carriage);
}

t_list		*vm_init_carriages(t_list *players)
{
	t_list          *carriages;
	t_carriage      *new_carriage;
	unsigned int    num;

	carriages = NULL;
	num = 0;
	while (players)
    {
	    if (!(new_carriage = cr_init(players->content, num)))
	        return (0);
	    ft_lstadd(&carriages, ft_lstpnew(new_carriage));
	    num++;
	    players = players->next;
    }
	return (carriages);
}

t_vm		*vm_init(int ac, char **av)
{
	t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		return (0);
	vm->cycles_to_die = CYCLE_TO_DIE;
	if (!(vm->players = vm_init_players(ac, av)))
	    return (0);
	vm->last_live_player = vm->players->content;
	if (!(vm->carriages = vm_init_carriages(vm->players)))
	    return (0);
	return (vm);
}