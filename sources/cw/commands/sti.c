//
// Created by esnowpea on 27.11.2020.
//

#include "corewar.h"

void	sti(t_carriage *car, t_vm *vm)
{
	if (((vm->arena[(car->position + 1) % MEM_SIZE] >> 4) & 3) == 1)
	{

	}
}