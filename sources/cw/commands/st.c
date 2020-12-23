//
// Created by esnowpea on 27.11.2020.
//

#include "corewar.h"

void	st(t_carriage *car, t_vm *vm)
{
	if (car->args[1].data.pos >= 3580 && car->args[1].data.pos <= 3602)
		ft_printf("");
	set_array(car->args[1].data, car->args[0].data, REG_SIZE);
}