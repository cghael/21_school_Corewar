/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_choose_new_filename.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:18:33 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 12:18:39 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_dis_choose_new_filename(t_dis *dis_s)
{
	char *tmp;

	while (FILE_EXIST == ft_dis_check_file_exist(dis_s) || dis_s->fd_s < 0)
	{
		ft_printf(FILE_EXIST_TXT, dis_s->file_s);
		ft_printf(FILE_INPUT_NEW);
		ft_dis_ask_new_filename(dis_s);
		if (FILE_NOT_EXIST == ft_dis_check_file_exist(dis_s))
		{
			if (EXIT_SUCCESS == ft_dis_try_create_file(dis_s))
				break ;
		}
	}
	ft_printf(FILE_SAVE_OK, dis_s->file_s);
	return (EXIT_SUCCESS);
}
