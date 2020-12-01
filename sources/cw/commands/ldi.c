//
// Created by esnowpea on 01.12.2020.
//

#include "corewar.h"

void		ldi(t_carriage *car, t_vm *vm)
{
	uint32_t	ind;
	uint32_t	i;

	ind = car->position + (ft_bitetoint(car->args[0].data,
			car->args[0].type == T_DIR ? 2 : REG_SIZE) +
			ft_bitetoint(car->args[1].data,
			car->args[1].type == T_DIR ? 2 : REG_SIZE)) % IDX_MOD;
	i = 0;
	while (ind < 0)
		ind += MEM_SIZE;
	while (i < REG_SIZE)
	{
		car->args[2].data[i] = vm->arena[(ind + i) % MEM_SIZE];
		i++;
	}
	if (ft_bitetoint(car->args[2].data, REG_SIZE) == 0)
		car->carry = 1;
	else
		car->carry = 0;
}