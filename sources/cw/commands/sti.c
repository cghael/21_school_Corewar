//
// Created by esnowpea on 27.11.2020.
//

#include "corewar.h"

void	sti(t_carriage *car, t_vm *vm)
{
	int32_t	ind;

	if (car->args[1].type == T_DIR)
		ind = (int16_t)ft_bytetoint(car->args[1].data, 2);
	else
		ind = ft_bytetoint(car->args[1].data, REG_SIZE);
	if (car->args[2].type == T_DIR)
		ind += (int16_t)ft_bytetoint(car->args[2].data, 2);
	else
		ind += ft_bytetoint(car->args[2].data, REG_SIZE);
	ind %= IDX_MOD;
	set_array(get_t_data(vm->arena, car->position + ind,
						 MEM_SIZE), car->args[0].data, REG_SIZE);
}