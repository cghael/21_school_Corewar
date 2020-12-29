/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:45:48 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/29 13:02:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "errors.h"

int		main(int ac, char **av)
{
	t_vm		*vm;
	t_player	*win_player;

	if (!(vm = vm_init(ac, av)))
		terminate(ERR_MALC_INIT);
	win_player = vm_operation(vm);
	if (vm->flag.d > 0 || vm->flag.dump > 0)
		vm_print_arena(vm);
	print_players((vm->players = pl_sort_rev_stack_champ(vm->players)));
	print_result(win_player);
	return (0);
}
