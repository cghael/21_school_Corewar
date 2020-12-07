/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:19:32 by esnowpea          #+#    #+#             */
/*   Updated: 2020/12/07 15:33:54 by ablane           ###   ########.fr       */
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
