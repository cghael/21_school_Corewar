/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_error_arg_types_code.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:46:05 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:46:05 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_dis_error_arg_types_code(t_dis *dis_s)
{
	int32_t		prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(STDERR_FILENO, ERR_DIS_CODE_TYPE, prefix + dis_s->pos);
	return (EXIT_FAILURE);
}
