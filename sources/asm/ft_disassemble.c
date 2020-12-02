/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disassemble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:05:47 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/23 16:05:51 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_disassemble(char *file_cor, t_asm *asm_s)
{
	t_dis		*dis_s;

	if (!(dis_s = ft_dis_init_struct(file_cor))
		|| EXIT_FAILURE == ft_dis_convert_start_filename(file_cor, dis_s))
		return (ft_dis_error(ERR_DIS_INIT, NULL));
	if (FILE_EXIST == ft_dis_check_file_exist(dis_s))
		ft_dis_choose_new_filename(dis_s);
	else
	{
		if (EXIT_FAILURE == ft_dis_try_create_file(dis_s))
			return (ft_dis_error(ERR_DIS_INIT, NULL));
	}
	ft_dprintf(2, "__ %s %d\n", dis_s->file_s, dis_s->fd_s);//todo del
	ft_dis_read_write(dis_s);
	if (dis_s->file_s != NULL)
		ft_dis_free_struct(dis_s);
	return (EXIT_SUCCESS);
}
