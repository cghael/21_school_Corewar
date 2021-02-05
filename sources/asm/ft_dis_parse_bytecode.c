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

void			ft_dis_parse_bytecode(t_dis *dis_s)
{
	if (ft_dis_parse_int32(
			dis_s->fd_cor,
			dis_s) != COREWAR_EXEC_MAGIC)
		ft_dis_terminate(
				ERR_DIS_MAGIC,
				dis_s);
	dis_s->name = ft_dis_parse_str(
			dis_s->fd_cor,
			PROG_NAME_LENGTH,
			dis_s);
	if (ft_dis_parse_int32(
			dis_s->fd_cor,
			dis_s) != 0)
		ft_dis_terminate(
				ERR_DIS_NO_NULL,
				dis_s);
	if ((dis_s->code_size = ft_dis_parse_int32(
			dis_s->fd_cor,
			dis_s)) < 0)
		ft_dis_terminate(
				ERR_DIS_CODE_SIZE,
				dis_s);
	dis_s->comment = ft_dis_parse_str(
			dis_s->fd_cor,
			COMMENT_LENGTH,
			dis_s);
	if (ft_dis_parse_int32(
			dis_s->fd_cor,
			dis_s) != 0)
		ft_dis_terminate(
				ERR_DIS_NO_NULL,
				dis_s);
	dis_s->code = ft_dis_parse_code(
			dis_s->fd_cor,
			(size_t) dis_s->code_size,
			dis_s);
}
