//
// Created by esnowpea on 27.11.2020.
//

#include "corewar.h"

t_player	*pl_find(t_list *players, uint32_t n)
{
	t_list	*tmp;

	tmp = players;
	while (tmp)
	{
		if (((t_player*)tmp->content)->number == n)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

void		live(t_carriage *car, t_vm *vm)
{
	uint8_t		arg[DIR_SIZE];

	vm->number_live++;
	car->number_last_live = vm->number_cycle;
	ft_memcpy(&arg, &vm->arena[(car->position + 1) % MEM_SIZE], DIR_SIZE);
	if (pl_find(vm->players, -ft_bitetoint(arg, DIR_SIZE)))
		vm->last_live_player =
				pl_find(vm->players, -ft_bitetoint(arg, DIR_SIZE));
}