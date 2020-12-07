//
// Created by esnowpea on 01.12.2020.
//

#include "corewar.h"

void		zjmp(t_carriage *car, t_vm *vm)
{
	if (car->carry == 1)
	{
		car->position += (((int16_t)ft_bytetoint(car->args[0].data, 2)) %
				IDX_MOD);
		while (car->position < 0)
			car->position += MEM_SIZE;
		car->position %= MEM_SIZE;
	}
}