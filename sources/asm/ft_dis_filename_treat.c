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
	char		*file_s;

	dot = ft_strrchr(file_cor, '.');
	if (!(tmp_name = ft_strsub(file_cor, 0, dot - file_cor)))
		return (ft_dis_error(ERR_DIS_FILE, NULL));
//	{
//		ft_asm_error("Error in ft_disassemble()\n", asm_s);//todo -> dis_err
//		return (EXIT_FAILURE);
//	}
	ft_printf("tmp_name [%s]\n", tmp_name);//todo del
	if (!(file_s = ft_strjoin(tmp_name, ".s")))
		return (ft_dis_error(ERR_DIS_FILE, tmp_name));
	ft_printf("file_diss [%s]\n", file_s);//todo del
	ft_dis_choose_new_filename(file_s, dis_s);
	if (!(dis_s->new_filename = ft_strjoin(dis_s->new_filename, ".s")))
	{
		if (dis_s->new_filename != NULL)
			free(dis_s->new_filename);
		return (ft_dis_error(ERR_DIS_FILE, tmp_name));
	}
	if (dis_s->fd_cor < 0)
	{
		ft_dis_error(ERR_DIS_FILE, file_s);
		return (EXIT_FAILURE);
	}
	free(file_s);
	return (EXIT_SUCCESS);
}
