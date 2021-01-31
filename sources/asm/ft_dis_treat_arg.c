/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_treat_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:09:38 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:09:39 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_treat_arg(t_dis *dis_s, t_elem *elem, unsigned int i)
{
	size_t		size;

	size = ft_dis_get_size(elem, i);
	if (dis_s->code_size - dis_s->pos >= (int32_t)size)
	{
		elem->args[i] = ft_dis_bytecode_to_int32(&dis_s->code[dis_s->pos],
												 size);
		dis_s->pos += size;
		if (elem->args_types[i] == T_REG && elem->args[i] <= 0)
			ft_dis_error_register(dis_s);
	}
	else
		ft_dis_error_length(dis_s);
}
