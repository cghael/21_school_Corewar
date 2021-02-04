/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:19:32 by esnowpea          #+#    #+#             */
/*   Updated: 2021/02/03 15:41:07 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_result(t_player *win_player)
{
	ft_printf("Contestant %d, \"%s\", has won !\n", win_player->number,
		win_player->name);
}

void		print_bit(uint8_t bit)
{
	char	*a;

	a = "0123456789abcdef";
	ft_putchar(a[bit / 16]);
	ft_putchar(a[bit % 16]);
}

void		pl_print_players(t_list *players)
{
	t_list	*player;
	int		n_players;
	int		n_step;

	n_players = ft_lstlength(players);
	ft_printf("Introducing contestants...\n");
	while (n_players)
	{
		player = players;
		n_step = n_players - 1;
		while (n_step)
		{
			player = player->next;
			n_step--;
		}
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",\
		((t_player*)player->content)->number, \
		((t_player*)player->content)->exec_size, \
		((t_player*)player->content)->name, \
		((t_player*)player->content)->comment);
		n_players--;
	}
}

void vm_print_arena(t_vm *vm)
{
	uint32_t	i;
	uint32_t	line;
	uint32_t	length;

	i = 0;
	ft_printf("%6s : ", "0x0000");
	if (vm->flag.d)
		length = 64;
	if (vm->flag.dump)
		length = 32;
	line = length;
	while (i < MEM_SIZE)
	{
		print_bit(vm->arena[i].byte);
		if ((i + 1) % length == 0 && (i + 1) != MEM_SIZE)
		{
			ft_printf(" \n%#5.4x : ", line);
			line += length;
		}
		else
			ft_printf(" ");
		i++;
	}
	ft_putchar('\n');
}
