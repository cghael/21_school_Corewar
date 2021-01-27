/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_arg_types_treat.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:38:21 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_arg_types_treat(t_dis *dis_s, t_elem *elems)
{
	int8_t		is_args_type;

	if (elems->op->is_args_type)
	{
		is_args_type = dis_s->code[dis_s->pos];
		if (elems->op->n_args >= 1)
			ft_dis_set_arg_type((int8_t)((is_args_type & 0xC0) \
					>> 6), 1, elems);
		if (elems->op->n_args >= 2)
			ft_dis_set_arg_type((int8_t)((is_args_type & 0x30) \
					>> 4), 2, elems);
		if (elems->op->n_args >= 3)
			ft_dis_set_arg_type((int8_t)((is_args_type & 0xC) \
					>> 2), 3, elems);
		ft_dis_validate_types_code(is_args_type, elems->op->n_args);
	}
	else
		elems->args_types[0] = elems->op->args[0];
}
