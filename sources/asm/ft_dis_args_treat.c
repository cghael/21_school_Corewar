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

static int		ft_right_opcode(t_elem *elem, t_dis *dis_s, uint8_t opcode)
{
	dis_s->pos++;
	elem->op = &g_ops[opcode - 1];
	if (elem->op->is_args_type && dis_s->pos >= dis_s->code_size)
	{
		free(elem);
		return (ft_dis_error_length(dis_s));
	}
	ft_dis_treat_arg_types(dis_s, elem);
	if (ft_dis_is_arg_types_valide(elem))
	{
		dis_s->pos += (elem->op->is_args_type) ? 1 : 0;
		if (EXIT_FAILURE == ft_dis_treat_args(dis_s, elem))
		{
			free(elem);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		free(elem);
		return (ft_dis_error_arg_types_code(dis_s));
	}
	return (EXIT_SUCCESS);
}

t_elem			*ft_dis_args_treat(t_dis *dis_s)
{
	t_elem		*elem;
	uint8_t		opcode;

	if ((elem = ft_dis_init_element()) == NULL)
		return (NULL);
	opcode = dis_s->code[dis_s->pos];
	if (opcode >= 0x01 && opcode <= 0x10)
	{
		if (EXIT_FAILURE == ft_right_opcode(elem, dis_s, opcode))
			return (NULL);
	}
	else
	{
		free(elem);
		return (ft_dis_error_opcode(dis_s));
	}
	return (elem);
}
