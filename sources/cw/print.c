/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:19:32 by esnowpea          #+#    #+#             */
/*   Updated: 2021/02/03 14:57:05 by ablane           ###   ########.fr       */
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

	player = players; //todo
//	players = player;
	ft_printf("Introducing contestants...\n");
	while (player)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",\
		((t_player*)player->content)->number, \
		((t_player*)player->content)->exec_size, \
		((t_player*)player->content)->name, \
		((t_player*)player->content)->comment);
		player = player->next;
	}
//	players = pl_sort_stack_champ(players); //todo
//	player = players;
}

void		vm_print_arena(t_vm *vm, uint32_t length)
{
	uint32_t	i;
	uint32_t	line;

	i = 0;
	ft_printf("%6s : ", "0x0000");
	line = length;
	while (i < MEM_SIZE)
	{
		print_bit(vm->arena[i]);
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
