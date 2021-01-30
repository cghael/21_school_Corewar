/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_arg_type_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:51:58 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:51:59 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_write_arg_type_code(t_asm *asm_s)
{
	int		shift;
	int		i;

	if (g_ops[asm_s->op_list->last->num].is_args_type == FALSE)
		return ;
	shift = 6;
	i = 0;
	while (i < g_ops[asm_s->op_list->last->num].n_args)
	{
		asm_s->op_list->last->args_code += \
									asm_s->op_list->last->args[i].type << shift;
		shift -= 2;
		i++;
	}
}
