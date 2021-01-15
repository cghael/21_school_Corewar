//
// Created by esnowpea on 27.11.2020.
//

#include "corewar.h"

void		ld(t_carriage *car, t_vm *vm)
{
	set_array(car->args[1].data, car->args[0].data, REG_SIZE);
	if (ft_bytetoint(car->args[1].data, REG_SIZE) == 0)
		car->carry = 1;
	else
		car->carry = 0;

}