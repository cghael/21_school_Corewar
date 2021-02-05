/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:37:15 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 12:37:15 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		lfork(t_carriage *car, t_vm *vm)
{
	t_carriage	*new_car;
	uint8_t		i;
	int32_t		ind;

	if (!(new_car = cr_init(car->player, vm->number_carriages++)))
		terminate(ERR_MALC_INIT);
	new_car->carry = car->carry;
	new_car->number_last_live = car->number_last_live;
	i = 0;
	while (i < REG_NUMBER)
	{
		set_array(get_t_data(new_car->reg[i], 0, REG_SIZE),
			get_t_data(car->reg[i], 0, REG_SIZE), REG_SIZE);
		i++;
	}
	ind = (int16_t)ft_bytetoint(car->args[0].data, IND_SIZE);
	if (car->operation != 0x0f)
		ind %= IDX_MOD;
	new_car->position = car->position + ind;
	while (new_car->position < 0)
		new_car->position += MEM_SIZE;
	new_car->position %= MEM_SIZE;
	ft_lstadd(&vm->carriages, ft_lstpnew(new_car));
}
