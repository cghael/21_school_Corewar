/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disassemble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:05:47 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 11:31:18 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_disassemble(char *file, t_asm *asm_s)
{
	t_dis		*dis_s;

	ft_printf("disassemble! [%s]\n", file);//todo del
	if (!(dis_s = ft_dis_init_struct()))
		return (ft_dis_error(ERR_DIS_INIT, NULL));
	if (EXIT_FAILURE == ft_dis_filename_treat(file, dis_s))
		return (ft_dis_error(ERR_DIS_INIT, dis_s));
	ft_printf("FD [%d] filename [%s]\n", dis_s->fd_cor, dis_s->file_s);//todo del debug
	//todo open FD -> add to dis_s
	if (EXIT_FAILURE == ft_dis_try_create_file(dis_s))
	{
		ft_dis_free_ctruct(dis_s);
		return (ft_dis_error(ERR_DIS, dis_s));
	}
	if (dis_s->file_s != NULL)
		ft_dis_free_ctruct(dis_s);
	return (EXIT_SUCCESS);
}
