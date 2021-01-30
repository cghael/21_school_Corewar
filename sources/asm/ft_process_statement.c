/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_statement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:45:51 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:45:53 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_elem			*ft_process_statement(t_dis *parser)
{
	t_elem		*statement;
	uint8_t		op_code;

	statement = ft_init_statement();
	op_code = parser->code[parser->pos];
	if (op_code >= 0x01 && op_code <= 0x10)
	{
		parser->pos++;
		statement->op = &g_ops[op_code - 1];
		if (statement->op->is_args_type && parser->pos >= parser->code_size)
			ft_length_error(parser);
		ft_process_arg_types(parser, statement);
		if (ft_is_arg_types_valide(statement))
		{
			if (statement->op->is_args_type)
				parser->pos++;
			ft_process_args(parser, statement);
		}
		else
			ft_arg_types_code_error(parser);
	}
	else
		ft_op_code_error(parser);
	return (statement);
}
