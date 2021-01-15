//
// Created by esnowpea on 27.11.2020.
//

#include "corewar.h"

void	st(t_carriage *car, t_vm *vm)
{
	set_array(car->args[1].data, car->args[0].data, REG_SIZE);

}