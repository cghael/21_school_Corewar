/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_validate_types_code.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:28:46 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 12:28:47 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_dis_validate_types_code(int8_t is_args_type, int n_args)
{
	int		arg_num;
	int8_t	type;

	arg_num = 4;
	while (arg_num > n_args)
	{
		type = (int8_t)((is_args_type >> (2 * (4 - arg_num))) & 0x3);
		if (type != 0)
		{
			ft_dis_error(ERR_DIS_TYPES, NULL);
			return ;
		}
		arg_num--;
	}
}
