/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:45:48 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/19 17:14:58 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "errors.h"

int		main(int ac, char **av)
{
	t_vm		*vm;
	t_player	*win_player;

	if (!(vm = pl_parsing_input(ac, av)))
	    terminate(ERR_MALC_INIT);
	vm_print_arena(vm);
	win_player = vm_operation(vm);
	print_result(win_player);
	return (0);
}
