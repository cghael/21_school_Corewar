//
// Created by esnowpea on 27.11.2020.
//

#include "corewar.h"

void		ld(t_carriage *car, t_vm *vm)
{
	uint8_t		ind;
	uint32_t	pos;

	if (((vm->arena[(car->position + 1) % MEM_SIZE] >> 6) & 3) == T_DIR)
	{
		ind = vm->arena[(car->position + 2 + DIR_SIZE) % MEM_SIZE] - 1;
		pos = (car->position + 2) % MEM_SIZE;
	}
	else
	{
		ind = vm->arena[(car->position + 2 + IND_SIZE) % MEM_SIZE] - 1;
		pos = (car->position + ft_bitetoint(vm->arena[(car->position + 2) %
				MEM_SIZE], IND_SIZE) % IDX_MOD) % MEM_SIZE;
	}
	ft_memcpy(&car->reg[ind], &vm->arena[pos], REG_SIZE);
	if (ft_bitetoint(car->reg[ind], REG_SIZE) == 0)
		car->carry = 1;
	else
		car->carry = 0;
}