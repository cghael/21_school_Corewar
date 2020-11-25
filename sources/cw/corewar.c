/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:45:48 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 11:31:18 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_vm		*vm;
	t_player	*win_player;

	vm = vm_init(ac, av);
	win_player = vm_operation(vm);
	print_result(win_player);
	return (0);
}
