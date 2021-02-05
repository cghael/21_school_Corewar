/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_parse_bytecode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:24:03 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:24:04 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_parse_bytecode(t_dis *dis_s)
{
	if (ft_dis_parse_int32(dis_s->fd_cor) != COREWAR_EXEC_MAGIC)
		return (EXIT_FAILURE);
	dis_s->name = ft_dis_parse_str(dis_s->fd_cor, PROG_NAME_LENGTH);
	if (dis_s->name == NULL)
		return (EXIT_FAILURE);
	if (ft_dis_parse_int32(dis_s->fd_cor) != 0)
		return (EXIT_FAILURE);
	if ((dis_s->code_size = ft_dis_parse_int32(dis_s->fd_cor)) < 0)
		return (EXIT_FAILURE);
	dis_s->comment = ft_dis_parse_str(dis_s->fd_cor, COMMENT_LENGTH);
	if (ft_dis_parse_int32(dis_s->fd_cor) != 0)
		return (EXIT_FAILURE);
	dis_s->code = ft_dis_parse_code(dis_s->fd_cor, (size_t)dis_s->code_size);
	if (dis_s->code == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
