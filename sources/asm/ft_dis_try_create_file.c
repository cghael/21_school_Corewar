/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_try_create_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:26:21 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 17:26:24 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_try_create_file(t_dis *dis_s)
{
	if (FILE_NOT_EXIST == ft_dis_check_file_correct(dis_s))
	{
		dis_s->fd_cor = open(dis_s->file_s, \
							 O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
		if (dis_s->fd_cor > 0)
			return (EXIT_SUCCESS);
		else
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
}
