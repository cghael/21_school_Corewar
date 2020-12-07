/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_elems_treat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:44:38 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 12:44:39 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_dis_print_typecode_err(void)
{
	ft_dis_error(ERR_DIS_ELEMS, NULL);
	ft_dis_error(ERR_DIS_TYPECODE, NULL);
}

static void		ft_dis_print_op_err(void)
{
	ft_dis_error(ERR_DIS_ELEMS, NULL);
	ft_dis_error(ERR_DIS_OPERATOR, NULL);
}

t_elem			*ft_dis_elems_treat(t_dis *dis_s)
{
	t_elem		*new_elem;
	uint8_t		op_code;

	new_elem = ft_dis_init_elem();
	op_code = dis_s->code[dis_s->pos];
	if (op_code >= 0x01 && op_code <= 0x10)
	{
		dis_s->pos++;
		new_elem->op = &g_ops[op_code - 1];
		if (new_elem->op->is_args_type && dis_s->pos >= dis_s->code_size)
			ft_dis_error(ERR_DIS_LEN_CODE, NULL);
		ft_dis_arg_types_treat(dis_s, new_elem);
		if (ft_dis_is_arg_types_valid(new_elem))
		{
			if (new_elem->op->is_args_type)
				dis_s->pos++;
			ft_dis_args_treat(dis_s, new_elem);
		}
		else
			ft_dis_print_typecode_err();
	}
	else
		ft_dis_print_op_err();
	return (new_elem);
}
