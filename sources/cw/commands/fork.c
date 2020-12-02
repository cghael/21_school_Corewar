//
// Created by esnowpea on 01.12.2020.
//

#include "corewar.h"

void		lfork(t_carriage *car, t_vm *vm)
{
	t_carriage	*new_car;
	uint8_t 	i;
	int32_t		ind;

	if (!(new_car = cr_init(car->player, ft_lstlength(vm->carriages))))
		terminate(ERR_MALC_INIT);
	new_car->carry = car->carry;
	new_car->number_last_live = car->number_last_live;
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_memcpy(new_car->reg[i], car->reg[i], REG_SIZE);
		i++;
	}
	ind = ft_bytetoint(car->args[0].data, car->args[0].len);
	if (car->operation == 0x0c)
		ind %= IDX_MOD;
	new_car->position = car->position + ind;
	while (new_car->position < 0)
		new_car->position += MEM_SIZE;
	new_car->position %= MEM_SIZE;
}