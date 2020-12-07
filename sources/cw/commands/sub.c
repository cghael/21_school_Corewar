//
// Created by esnowpea on 01.12.2020.
//

#include "corewar.h"

void		sub(t_carriage *car, t_vm *vm)
{
	int32_t		num;

	num = ft_bytetoint(car->args[0].data, REG_SIZE) -
		  ft_bytetoint(car->args[1].data, REG_SIZE);
	ft_memcpy(car->args[2].data.data, &(num), REG_SIZE);
	if (ft_bytetoint(car->args[2].data, REG_SIZE) == 0)
		car->carry = 1;
	else
		car->carry = 0;
}