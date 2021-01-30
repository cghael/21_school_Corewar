/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:19:17 by esnowpea          #+#    #+#             */
/*   Updated: 2021/01/30 14:25:52 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_data		get_t_data(uint8_t *array, int32_t pos, uint32_t max)
{
	t_data		data;

	while (pos < 0)
		pos += max;
	data.data = array;
	data.pos = max == 0 ? pos : pos % max;
	data.max = max;
	return (data);
}

t_data		get_dir(uint8_t n, t_carriage *car, t_vm *vm)
{
	return (get_t_data(vm->arena, car->args[n].pos, MEM_SIZE));
}

t_data		get_reg(uint8_t n, t_carriage *car, t_vm *vm)
{
	uint8_t		reg_nb;

	reg_nb = ft_bytetoint(get_t_data(vm->arena, car->args[n].pos,
		MEM_SIZE), 1);
	car->args[n].reg_nb = reg_nb;
	if (reg_nb < 1 || reg_nb > REG_NUMBER)
		return (get_t_data(0, 0, 0));
	return (get_t_data(car->reg[reg_nb - 1], 0, REG_SIZE));
}

t_data		get_ind(uint8_t n, t_carriage *car, t_vm *vm)
{
	int16_t		ind;

	ind = ft_bytetoint(get_t_data(vm->arena, car->args[n].pos, MEM_SIZE),
			IND_SIZE);
	if (car->operation != 0x0d && car->operation != 0x0e)
		ind %= IDX_MOD;
	return (get_t_data(vm->arena, car->position + ind, MEM_SIZE));
}

t_data		get_data(uint8_t n, t_carriage *car, t_vm *vm)
{
	if (car->args[n].type == T_DIR)
		return (get_dir(n, car, vm));
	else if (car->args[n].type == T_REG)
		return (get_reg(n, car, vm));
	else
		return (get_ind(n, car, vm));
}
