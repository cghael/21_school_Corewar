//
// Created by esnowpea on 01.12.2020.
//

#include "corewar.h"

void		ldi(t_carriage *car, t_vm *vm)
{
	int32_t	ind;

	if (car->args[0].type == T_DIR)
		ind = (int16_t)ft_bytetoint(car->args[0].data, IND_SIZE);
	else
		ind = ft_bytetoint(car->args[0].data, REG_SIZE);
	if (car->args[1].type == T_DIR)
		ind += (int16_t)ft_bytetoint(car->args[1].data, IND_SIZE);
	else
		ind += ft_bytetoint(car->args[1].data, REG_SIZE);
	if (car->operation != 0x0e)
		ind %= IDX_MOD;
	set_array(car->args[2].data,
		   get_t_data(vm->arena, car->position + ind, MEM_SIZE), REG_SIZE);
	if (ft_bytetoint(car->args[2].data, REG_SIZE) == 0 &&
		car->operation != 0x0a)
		car->carry = 1;
	else
		car->carry = 0;
}