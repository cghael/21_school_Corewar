/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_validate_code_types.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:40:05 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:40:07 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_dis_validate_code_types(t_dis *dis_s, int8_t args_types_code, \
																int args_num)
{
	int		arg_num;
	int8_t	type;

	arg_num = 4;
	while (arg_num > args_num)
	{
		type = (int8_t)((args_types_code >> (2 * (4 - arg_num))) & 0x3);
		if (type != 0)
		{
			ft_dis_code_types_warning((size_t)dis_s->pos);
			return ;
		}
		arg_num--;
	}
}
