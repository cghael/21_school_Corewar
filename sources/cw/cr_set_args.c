/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:16:34 by esnowpea          #+#    #+#             */
/*   Updated: 2021/01/30 14:19:10 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "asm_op.h"

void		cr_set_args_type(t_carriage *car, t_vm *vm)
{
	uint8_t		arg_code;
	uint8_t		i;

	arg_code = vm->arena[(car->position + 1) % MEM_SIZE];
	i = 0;
	if (g_ops[car->operation - 1].is_args_type)
		while (i < g_ops[car->operation - 1].n_args)
		{
			car->args[i].type = ((arg_code >> (6 - i * 2)) & 3) == IND_CODE ?
								T_IND : ((arg_code >> (6 - i * 2)) & 3);
			car->args[i].len = find_len_arg(car->args[i].type, car->operation);
			i++;
		}
	else
	{
		car->args[0].type = g_ops[car->operation - 1].args[0];
		car->args[0].len = find_len_arg(car->args[0].type, car->operation);
	}
}

void		cr_set_args_pos(t_carriage *car, t_vm *vm)
{
	uint8_t		i;
	uint32_t	pos;

	i = 0;
	(void)vm;
	pos = (car->position + 2) % MEM_SIZE;
	if (g_ops[car->operation - 1].is_args_type)
		while (i < g_ops[car->operation - 1].n_args)
		{
			car->args[i].pos = pos;
			pos += car->args[i].len;
			pos %= MEM_SIZE;
			i++;
		}
	else
		car->args[0].pos = (car->position + 1) % MEM_SIZE;
}

void		cr_set_args_data(t_carriage *car, t_vm *vm)
{
	uint8_t		i;

	i = 0;
	while (i < g_ops[car->operation - 1].n_args)
	{
		car->args[i].data = get_data(i, car, vm);
		i++;
	}
}

void		cr_set_args_null(t_carriage *car, t_vm *vm)
{
	uint8_t		i;

	i = 0;
	(void)vm;
	while (i < 3)
	{
		car->args[i].data = get_t_data(0, 0, 0);
		car->args[i].type = 0;
		car->args[i].pos = 0;
		car->args[i].len = 0;
		car->args[i].reg_nb = 0;
		i++;
	}
}

uint8_t		cr_set_args(t_carriage *car, t_vm *vm)
{
	uint8_t		i;

	cr_set_args_null(car, vm);
	cr_set_args_type(car, vm);
	cr_set_args_pos(car, vm);
	cr_set_args_data(car, vm);
	car->args_len = len_args(car, vm);
	i = 0;
	while (i < g_ops[car->operation - 1].n_args)
	{
		if (car->args[i].type == T_REG && car->args[i].data.max == 0)
			return (0);
		i++;
	}
	return (1);
}
