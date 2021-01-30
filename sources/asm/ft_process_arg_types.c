/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_arg_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:45:06 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/30 16:45:07 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_treat_arg_types(t_dis *dis_s, t_elem *elem)
{
	int8_t		args_types_code;

	if (elem->op->is_args_type)
	{
		args_types_code = dis_s->code[dis_s->pos];
		if (elem->op->n_args >= 1)//todo dsaflksdgrlkjgsdplrl! *P
			ft_set_arg_type((int8_t) ((args_types_code & 0xC0)
					>> 6), 1, elem);
		if (elem->op->n_args >= 2)
			ft_set_arg_type((int8_t) ((args_types_code & 0x30)
					>> 4), 2, elem);
		if (elem->op->n_args >= 3)
			ft_set_arg_type((int8_t) ((args_types_code & 0xC)
					>> 2), 3, elem);
		ft_validate_code_types(dis_s, args_types_code, elem->op->n_args);
	}
	else
		elem->args_types[0] = elem->op->args[0];
}
