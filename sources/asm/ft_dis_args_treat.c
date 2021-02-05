/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_args_treat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:47:36 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:47:36 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** func treating all elems by a args_type
*/

t_elem			*ft_dis_args_treat(t_dis *dis_s)
{
	t_elem		*elem;
	uint8_t		opcode;

	elem = ft_dis_init_element(dis_s);
	if (elem == NULL)
		return (NULL);
	opcode = dis_s->code[dis_s->pos];
	if (opcode >= 0x01 && opcode <= 0x10)
	{
		dis_s->pos++;
		elem->op = &g_ops[opcode - 1];
		if (elem->op->is_args_type && dis_s->pos >= dis_s->code_size)
			return (ft_dis_error_length(dis_s));
		ft_dis_treat_arg_types(dis_s, elem);
		if (ft_dis_is_arg_types_valide(elem))
		{
			if (elem->op->is_args_type)
				dis_s->pos++;
			if (EXIT_FAILURE == ft_dis_treat_args(dis_s, elem))
				return (NULL);
		}
		else
			return (ft_dis_error_arg_types_code(dis_s));
	}
	else
		return (ft_dis_error_opcode(dis_s));
	return (elem);
}
