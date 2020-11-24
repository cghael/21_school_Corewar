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

int		ft_dis_check_file_exist(char *filename)
{
	if ((open(filename, O_RDONLY)) >= 0)
	{
		ft_printf(FILE_EXIST_TXT, filename);
		return (FILE_EXIST);
	}
	ft_printf(FILE_NOT_EXIST_TXT, filename);
	return (FILE_NOT_EXIST);
}
