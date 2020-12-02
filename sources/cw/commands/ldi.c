//
// Created by esnowpea on 01.12.2020.
//

#include "corewar.h"

void		ldi(t_carriage *car, t_vm *vm)
{
	int32_t	ind;

	ind = car->position + (ft_bytetoint(car->args[0].data,
			car->args[0].type == T_DIR ? 2 : REG_SIZE) +
			ft_bytetoint(car->args[1].data,
			car->args[1].type == T_DIR ? 2 : REG_SIZE)) % IDX_MOD;
	set_array(car->args[2].data, get_t_data(vm->arena, car->position + ind,
		MEM_SIZE), REG_SIZE);
	if (ft_bytetoint(car->args[2].data, REG_SIZE) == 0)
		car->carry = 1;
	else
		car->carry = 0;
}