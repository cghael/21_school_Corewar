/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_arg_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:45:15 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:45:17 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_process_arg_types(t_dis *parser, t_elem *statement)
{
	int8_t args_types_code;

	if (statement->op->is_args_type)
	{
		args_types_code = parser->code[parser->pos];
		if (statement->op->n_args >= 1)
			ft_set_arg_type((int8_t)((args_types_code & 0xC0)
					>> 6), 1, statement);
		if (statement->op->n_args >= 2)
			ft_set_arg_type((int8_t)((args_types_code & 0x30)
					>> 4), 2, statement);
		if (statement->op->n_args >= 3)
			ft_set_arg_type((int8_t)((args_types_code & 0xC)
					>> 2), 3, statement);
		ft_validate_code_types(parser, args_types_code, statement->op->n_args);
	}
	else
		statement->args_types[0] = statement->op->args[0];
}
