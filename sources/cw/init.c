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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_player	*pl_init(char *filename, uint32_t number)
{
	int			fd;
	uint8_t		buf[4];
	t_player	*player;

	player = ft_memalloc(sizeof(t_player));
	fd = open(filename, O_RDONLY, S_IREAD | S_IWRITE);
	read(fd, buf, 4);
	read(fd, player->name, PROG_NAME_LENGTH);
	read(fd, buf, 4);
	read(fd, buf, 4);
	player->exec_size = buf[3];
	read(fd, player->comment, COMMENT_LENGTH);
	read(fd, buf, 4);
	read(fd, player->exec_code, CHAMP_MAX_SIZE);
	player->number = number;
	return (player);
}

t_list		*vm_init_players(int ac, char **av)
{
	t_list		*players;
	u_int8_t	i;

	players = NULL;
	i = 1;
	while (i < ac)
	{
		ft_lstadd(&players, ft_lstpnew(pl_init(av[i], i)));
		i++;
	}
	return (players);
}

void		vm_init_arena(t_vm *vm)
{
	t_list			*tmp;
	t_player		*player;

	tmp = vm->players;
	while (tmp)
	{
		player = (t_player*)tmp->content;
		ft_memcpy_cor(&vm->arena[MEM_SIZE / vm->number_players *
				(player->number - 1) % MEM_SIZE],
				player->exec_code, player->exec_size, MEM_SIZE);
		tmp = tmp->next;
	}
}

t_carriage  *cr_init(t_player *player, uint32_t nb)
{
    t_carriage  *carriage;
	int32_t		minus_num;

    if (!(carriage = ft_memalloc(sizeof(t_carriage))))
        return (0);
    carriage->number = nb;
    minus_num = -player->number;
	ft_memcpy(&carriage->reg[0], &(minus_num), REG_SIZE);
    carriage->player = player;
    return (carriage);
}

t_list		*vm_init_carriages(t_list *players)
{
	t_list			*tmp;
	t_list          *carriages;
	t_carriage      *new;
	uint32_t	    num;

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
	vm->cycles_to_die = CYCLE_TO_DIE;
	if (!(vm->players = vm_init_players(ac, av)))
	    return (0);
	vm->number_players = ft_lstlength(vm->players);
	vm->last_live_player = vm->players->content;
	vm_init_arena(vm);
	if (!(vm->carriages = vm_init_carriages(vm->players)))
	    return (0);
	return (vm);
}