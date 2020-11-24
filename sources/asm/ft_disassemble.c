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
	if (EXIT_FAILURE == ft_dis_filename_treat(file, dis_s))
		return (ft_dis_error(ERR_DIS_INIT, dis_s));
	ft_printf("FD [%d] filename [%s]\n", dis_s->fd_cor, dis_s->file_s);//todo del debug
	//todo open FD -> add to dis_s
//	dis_s->fd_cor = open(dis_s->file_s, \
//								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);//todo must be in finally
	return (EXIT_SUCCESS);
}
