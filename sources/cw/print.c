/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:19:32 by esnowpea          #+#    #+#             */
/*   Updated: 2020/12/09 12:34:38 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_players(t_list *champ)
{
	t_list	*cham;

	cham = pl_sort_rev_stack_champ(champ);
	ft_printf("Introducing contestants...\n");
	while (cham)
	{
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\")\n",
				  ((t_player*)cham->content)->number,
				  ((t_player*)cham->content)->exec_size,
				  ((t_player*)cham->content)->name,
				  ((t_player*)cham->content)->comment);
		cham = cham->next;
	}
	ft_printf("\n\n");
}

void		print_result(t_player *win_player)
{
	ft_printf("Contestant %d, \"%s\", has won !", win_player->number,
		   win_player->name);
	//TODO print_result
}

void		print_bit(uint8_t bit)
{
	char	a[] = "0123456789abcdef";

	ft_putchar(a[bit / 16]);
	ft_putchar(a[bit % 16]);
}

void		vm_print_arena(t_vm *vm)
{
	uint32_t	i;

	i = 0;
	ft_printf("%6d : ", vm->number_cycle);
	while (i < MEM_SIZE)
	{
		print_bit(vm->arena[i]);
		if ((i + 1) % 64 == 0 && (i + 1) != MEM_SIZE)
			ft_printf("\n0x0000 : ");
		else
			ft_printf(" ");
		i++;
	}
	ft_printf("\n\n\n");
}
