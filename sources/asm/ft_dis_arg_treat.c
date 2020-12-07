/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_arg_treat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:41:54 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 12:41:56 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_dis_arg_treat(t_dis *dis_s, t_elem *elems, unsigned i)
{
	size_t		size;

	size = ft_dis_get_size(elems, i);
	if (dis_s->code_size - dis_s->pos >= (int32_t)size)
	{
		elems->args[i] = ft_dis_bytecode_to_int32(&dis_s->code[dis_s->pos],
												size);
		dis_s->pos += size;
		if (elems->args[i] == T_REG && elems->args[i] <= 0)
			ft_dis_error(ERR_DIS_ARGS_TREAT, NULL);
	}
	else
	{
		ft_dis_error(ERR_DIS_ARGS_TREAT, NULL);
		ft_dis_error(ERR_DIS_LENGTH, NULL);
	}
}
