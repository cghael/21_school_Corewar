/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_bytecode_to_int32.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:27:18 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:27:19 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** "magic" func - convert bytecode to int32 by a size parts.
** sign used for byte inverse if [0] elem is 1
** [size - 1] - because in g_ops[16] only 15 elems, lol
*/

int32_t		ft_dis_bytecode_to_int32(const uint8_t *bytecode, size_t size)
{
	int32_t	res;
	t_bool	sign;
	int		i;

	res = 0;
	sign = (t_bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			res += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			res += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		res = ~(res);
	return (res);
}
