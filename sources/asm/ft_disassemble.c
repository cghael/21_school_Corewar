/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disassemble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:05:47 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_disassemble(char *file_cor, t_asm *asm_s)
{
	t_dis	*dis_s;

	(void)asm_s;
	if (!(dis_s = ft_dis_init_struct(file_cor))
		|| EXIT_FAILURE == ft_dis_convert_start_filename(file_cor, dis_s))
		return (ft_dis_error_free_dis_s(ERR_DIS_INIT, NULL, dis_s));
	if (FILE_EXIST == ft_dis_check_file_exist(dis_s))
		ft_dis_choose_new_filename(dis_s);
	else
	{
		if (EXIT_FAILURE == ft_dis_try_create_file(dis_s))
			return (ft_dis_error_free_dis_s(ERR_DIS_CRT_FILE, NULL, dis_s));
	}
	ft_dis_read_write(dis_s);
	ft_dis_free_struct(dis_s);
	return (EXIT_SUCCESS);
}
