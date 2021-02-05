/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_error_register.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:43:56 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:43:57 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_dis_error_register(t_dis *dis_s)
{
	int32_t		prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(STDERR_FILENO, ERR_DIS_REGISTER, prefix + dis_s->pos);
	ft_dis_free_struct(dis_s);
	return (EXIT_FAILURE);
}
