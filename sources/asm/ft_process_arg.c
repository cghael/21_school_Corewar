/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:44:45 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_op.h"
#include "asm.h"

void			ft_process_arg(t_dis *parser, t_elem *statement, unsigned i)
{
	size_t size;

	size = ft_get_size(statement, i);
	if (parser->code_size - parser->pos >= (int32_t)size)
	{
		statement->args[i] = ft_bytecode_to_int32(&parser->code[parser->pos],
												  size);
		parser->pos += size;
		if (statement->args_types[i] == T_REG && statement->args[i] <= 0)
			ft_register_error(parser);
	}
	else
		ft_dis_length_error(parser);
}
