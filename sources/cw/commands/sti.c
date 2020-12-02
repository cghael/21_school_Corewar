//
// Created by esnowpea on 27.11.2020.
//

#include "corewar.h"

void	sti(t_carriage *car, t_vm *vm)
{
	int32_t	ind;

	ind = (ft_bytetoint(car->args[1].data,
			car->args[1].type == T_DIR ? 2 : REG_SIZE) +
			ft_bytetoint(car->args[2].data,
			car->args[2].type == T_DIR ? 2 : REG_SIZE)) % IDX_MOD;
	set_array(get_t_data(vm->arena, car->position + ind,
						 MEM_SIZE), car->args[0].data, REG_SIZE);
}