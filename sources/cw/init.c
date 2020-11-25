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

t_list		*vm_init_players(int ac, char **av)
{
    t_list		*players;

    players = NULL;
    //TODO parsing and add players to list with number
    return (players);
}

void		vm_init_arena(t_vm *vm)
{
	t_list			*tmp;
	t_player		*player;
	unsigned int	n;

	n = vm->last_live_player->number;
	tmp = vm->players;
	while (tmp)
	{
		player = (t_player*)tmp->content;
		ft_memcpy(&vm->arena[MEM_SIZE / n * (player->number - 1) % MEM_SIZE],
				  player->exec_code, player->exec_size);
		tmp = tmp->next;
	}
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
	vm_init_arena(vm);
	if (!(vm->carriages = vm_init_carriages(vm->players)))
	    return (0);
	return (vm);
}