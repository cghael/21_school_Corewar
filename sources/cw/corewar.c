/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:45:48 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 12:36:53 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_vm		*vm;
	t_player	*win_player;

	if (!(vm = vm_init(ac, av)))
	    terminate(ERR_MALC_INIT);
	win_player = vm_operation(vm);
	print_result(win_player);
	return (0);
}
