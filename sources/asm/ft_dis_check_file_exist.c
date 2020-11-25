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

int			ft_dis_check_file_exist(char *filename)
{
	int		fd;

//	ft_dprintf(2, "FILE [%s]\n", filename);//todo del
	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		return (FILE_EXIST);
	}
	return (FILE_NOT_EXIST);
}
