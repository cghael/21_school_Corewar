/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_filename_treat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:19:11 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 12:19:13 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_filename_treat(char *file_cor, t_dis *dis_s)
{
	char		*dot;
	char		*tmp_name;

	dot = ft_strrchr(file_cor, '.');
	if (!(tmp_name = ft_strsub(file_cor, 0, dot - file_cor)))
		return (ft_dis_error(ERR_DIS_FILE, tmp_name));
//	ft_printf("__tmp_name [%s]\n", tmp_name);//todo del
	if (!(dis_s->file_s = ft_strjoin(tmp_name, ".s")))
		return (ft_dis_error(ERR_DIS_FILE, tmp_name));
//	ft_printf("__file_s [%s]\n", dis_s->file_s);//todo del
	ft_dis_choose_new_filename(dis_s);

ft_dprintf(2, "KEKSOLOL!\n");
	if (!(dis_s->file_s = ft_strjoin(dis_s->file_s, ".s")))
	{
		if (dis_s->file_s != NULL)
			free(dis_s->file_s);
		return (ft_dis_error(ERR_DIS_FILE, tmp_name));
	}


	if (dis_s->fd_cor < 0)
		return (ft_dis_error(ERR_DIS_FILE, dis_s->file_s));
	free(dis_s->file_s);
	return (EXIT_SUCCESS);
}
