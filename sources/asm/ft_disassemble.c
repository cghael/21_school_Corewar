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

int				ft_disassemble(char *file, t_asm *asm_s)
{
	t_dis		*dis_s;

	ft_printf("disassemble! [%s]\n", file);//todo del
	if (!(dis_s = ft_dis_init_struct()))
		return (ft_dis_error(ERR_DIS_INIT, NULL));
	//todo ft_dis_convert_start_filename();
	ft_dis_copy_filename(file, dis_s);
	ft_dis_del_cor(dis_s);
	ft_dis_add_s(dis_s);
	ft_printf("init struct: FD [%d] filename [%s]\n", dis_s->fd_cor, dis_s->file_s);//todo del debug
	exit(77);//todo break
	if (EXIT_FAILURE == ft_dis_try_create_file(dis_s))
	{
		ft_dis_free_struct(dis_s);
		return (ft_dis_error(ERR_DIS, dis_s));
	}
	if (dis_s->file_s != NULL)
		ft_dis_free_struct(dis_s);
	return (EXIT_SUCCESS);
}
