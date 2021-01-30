/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:10:52 by esnowpea          #+#    #+#             */
/*   Updated: 2021/01/30 12:48:15 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		vm_init_arena(t_vm *vm)
{
	t_list			*tmp;
	t_player		*player;

	tmp = vm->players;
	while (tmp)
	{
		player = (t_player*)tmp->content;
		set_array(get_t_data(vm->arena,\
		MEM_SIZE / vm->number_players * (player->number - 1), MEM_SIZE),
		get_t_data(player->exec_code, 0, player->exec_size), player->exec_size);
		tmp = tmp->next;
	}
}

t_carriage	*cr_init(t_player *player, uint32_t nb)
{
	t_carriage	*carriage;

	if (!(carriage = ft_memalloc(sizeof(t_carriage))))
		return (0);
	carriage->number = nb;
	ft_inttobyte(-player->number, get_t_data(carriage->reg[0], 0, REG_SIZE),
		REG_SIZE);
	carriage->player = player;
	return (carriage);
}

t_list		*vm_init_carriages(t_list *players)
{
	t_list			*carriages;
	t_list			*tmp;
	t_carriage		*new;
	uint32_t		num;

	carriages = NULL;
	num = 0;
	tmp = players;
	while (tmp)
	{
		if (!(new = cr_init(tmp->content, num)))
			return (0);
		new->position = MEM_SIZE / ((t_player*)players->content)->number *
				(((t_player*)tmp->content)->number - 1) % MEM_SIZE;
		ft_lstadd(&carriages, ft_lstpnew(new));
		num++;
		tmp = tmp->next;
	}
	return (carriages);
}

t_vm		*vm_init(int ac, char **av)
{
	t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		return (0);
	vm->flag.visual = 0;
	vm->flag.dump = 0;
	vm->flag.d = 0;
	vm->flag.a = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	if (!(vm->players = pl_init_players(ac, av)))
		return (0);
	fl_check_flags(ac, av, vm);
	vm->number_players = ft_lstlength(vm->players);
	vm->last_live_player = vm->players->content;
	vm_init_arena(vm);
	if (!(vm->carriages = vm_init_carriages(vm->players)))
		return (0);
	vm->number_carriages = ft_lstlength(vm->carriages);
	return (vm);
}
