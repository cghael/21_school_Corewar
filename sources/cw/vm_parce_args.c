/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parce_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:12:20 by esnowpea          #+#    #+#             */
/*   Updated: 2021/01/30 14:19:10 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "asm_op.h"

void		set_array(t_data dest, const t_data source, uint32_t n)
{
	uint32_t	i;

	i = 0;
	while (dest.pos < 0)
		dest.pos += dest.max;
	while (i < n)
	{
		dest.data[(dest.pos + i) % dest.max] =
				source.data[(source.pos + i) % source.max];
		i++;
	}
}

uint8_t		find_len_arg(uint8_t arg, uint8_t operation)
{
	if (arg == T_REG)
		return (1);
	if (arg == T_DIR)
		return (g_ops[operation - 1].t_dir_size);
	if (arg == T_IND)
		return (2);
	return (0);
}

uint32_t	len_args(t_carriage *car, t_vm *vm)
{
	uint32_t		sum;
	t_op			op;
	uint8_t			arg_code;

	arg_code = vm->arena[(car->position + 1) % MEM_SIZE];
	op = g_ops[car->operation - 1];
	if (op.is_args_type)
	{
		sum = 2 + find_len_arg(((arg_code >> 6) & 3) == IND_CODE ?
							   T_IND : ((arg_code >> 6) & 3), car->operation);
		if (op.n_args > 1)
			sum += find_len_arg(((arg_code >> 4) & 3) == IND_CODE ?
								T_IND : ((arg_code >> 4) & 3), car->operation);
		if (op.n_args > 2)
			sum += find_len_arg(((arg_code >> 2) & 3) == IND_CODE ?
								T_IND : ((arg_code >> 2) & 3), car->operation);
	}
	else
		sum = 1 + op.t_dir_size;
	return (sum);
}

uint32_t	check_args(t_carriage *car, t_vm *vm)
{
	t_op			op;
	uint8_t			byte;

	byte = vm->arena[(car->position + 1) % MEM_SIZE];
	op = g_ops[car->operation - 1];
	if (!op.is_args_type || (op.n_args == 3 && (op.args[0] &
			(((byte >> 6) & 3) == IND_CODE ? T_IND : ((byte >> 6) & 3)) &&
			(op.args[1] &
			(((byte >> 4) & 3) == IND_CODE ? T_IND : ((byte >> 4) & 3))) &&
			(op.args[2] &
			(((byte >> 2) & 3) == IND_CODE ? T_IND : ((byte >> 2) & 3))))) ||
			(op.n_args == 2 && (op.args[0] &
			(((byte >> 6) & 3) == IND_CODE ? T_IND : ((byte >> 6) & 3))) &&
		 	(op.args[1] &
		 	(((byte >> 4) & 3) == IND_CODE ? T_IND : ((byte >> 4) & 3)))) ||
		 	(op.n_args == 1 && (op.args[0] &
			(((byte >> 6) & 3) == IND_CODE ? T_IND : ((byte >> 6) & 3)))))
		return (1);
	return (0);
}
