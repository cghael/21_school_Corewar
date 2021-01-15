/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_parse_bytecode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:43:57 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_parse_bytecode(t_dis *dis_s)
{
	if (ft_dis_parse_int32(dis_s->fd_cor) != COREWAR_EXEC_MAGIC)
		return (ft_dis_error(ERR_DIS_MAGIC, NULL));
	dis_s->name = ft_dis_parse_string(dis_s->fd_cor, PROG_NAME_LENGTH);
	if (ft_dis_parse_int32(dis_s->fd_cor) != 0)
		return (ft_dis_error(ERR_DIS_NO_NULL, NULL));
	if ((dis_s->code_size = ft_dis_parse_int32(dis_s->fd_cor)) < 0)
		return (ft_dis_error(ERR_DIS_CODE_SIZE, NULL));
	dis_s->comment = ft_dis_parse_string(dis_s->fd_cor, COMMENT_LENGTH);
	if (ft_dis_parse_int32(dis_s->fd_cor) != 0)
		return (ft_dis_error(ERR_DIS_NO_NULL, NULL));
	dis_s->code = ft_dis_parse_code(dis_s->fd_cor, (size_t)dis_s->code_size);
	return (EXIT_SUCCESS);
}
