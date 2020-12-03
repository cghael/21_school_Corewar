/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:19:32 by esnowpea          #+#    #+#             */
/*   Updated: 2020/12/03 14:43:11 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	while (i < MEM_SIZE)
	{
		print_bit(vm->arena[i]);
		if ((i + 1) % 32 == 0)
			ft_printf("\n");
		else
			ft_printf(" ");
		i++;
	}
	ft_printf("\n\n\n");
}
