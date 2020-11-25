/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_check_file_correct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:45:07 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 13:45:08 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** func try open filename.
**
** RETURN VALUES:
**
** if SUCCESS - FILE_EXIST (0) && close opened FD
** if FAILURE - FILE_NOT_EXIST (1)
*/

int ft_dis_check_file_correct(t_dis *dis_s)
{
//	dis_s->fd_cor = open(dis_s->file_s, O_RDONLY);
//	if (dis_s->fd_cor >= 0)
//	{
//		close(dis_s->fd_cor);
//		dis_s->fd_cor = -1;
//		return (FILE_EXIST);
//	}
	if (EXIT_FAILURE == ft_dis_try_create_file(dis_s))
		return (FILE_EXIST);

	return (FILE_NOT_EXIST);
}
