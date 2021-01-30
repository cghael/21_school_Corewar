/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bytecode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:41:05 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:41:07 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_parse_bytecode(t_dis *parser)
{
	if (ft_parse_int32(parser->fd_cor) != COREWAR_EXEC_MAGIC)
		ft_terminate(ERR_INVALID_MAGIC);
	parser->name = ft_parse_str(parser->fd_cor, PROG_NAME_LENGTH);
	if (ft_parse_int32(parser->fd_cor) != 0)
		ft_terminate(ERR_NO_NULL);
	if ((parser->code_size = ft_parse_int32(parser->fd_cor)) < 0)
		ft_terminate(ERR_INVALID_CODE_SIZE);
	parser->comment = ft_parse_str(parser->fd_cor, COMMENT_LENGTH);
	if (ft_parse_int32(parser->fd_cor) != 0)
		ft_terminate(ERR_NO_NULL);
	parser->code = ft_parse_code(parser->fd_cor, (size_t) parser->code_size);
}
