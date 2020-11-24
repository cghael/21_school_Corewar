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

void			ft_dis_choose_new_filename(char *file_disassemble, t_dis *dis_s)
{
	char		*answer;
	char		*new_filename;

	new_filename = ft_strnew(0);
	answer = ft_strnew(0);
	if (!new_filename || !answer)
		ft_dis_error(ERR_DIS_CHOOSE, NULL);
//		ft_asm_error("in ft_dis_filename_treat()\n", asm_s);//todo -> dis_err
//	if ((dis_s->fd_cor = open(file_disassemble, O_RDONLY)) >= 0)//todo hmmm?
	if ((open(file_disassemble, O_RDONLY)) >= 0)
	{
		ft_printf(FILE_EXIST, file_disassemble);
		scanf("%s", new_filename);
		if (STRINGS_EQU != ft_strequ(answer, "Y"))
		{
			ft_printf(Q_CORRECT_NAME, new_filename);
			scanf("%s", answer);
			ft_dis_correct_input(answer, file_disassemble, new_filename, dis_s);
		}
	}
	else
	{
		ft_printf("i cant OPEN FILE_DISSSS!!!!!!!\n");//todo del
		dis_s->new_filename = ft_strdup(file_disassemble);
//		dis_s->fd_cor = open(file_disassemble, \
//								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	}
}
