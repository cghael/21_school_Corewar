/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opcode_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:38:04 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:38:06 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_op_code_error(t_dis *parser)
{
	int32_t	prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(2, "Incorrect operator code at %u byte\n",
			   prefix + parser->pos);
	exit(0);
}
