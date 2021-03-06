/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_check_file_exist.c                          :+:      :+:    :+:   */
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

int		ft_dis_check_file_exist(t_dis *dis_s)
{
	dis_s->fd_s = open(dis_s->file_s, O_RDONLY);
	if (dis_s->fd_s >= 0)
	{
		if (EXIT_SUCCESS == close(dis_s->fd_s))
			return (FILE_EXIST);
		else
			perror(ERR_CLOSE_FILE);
	}
	return (FILE_NOT_EXIST);
}
