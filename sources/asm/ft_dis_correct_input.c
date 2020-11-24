/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_correct_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:18:49 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 12:18:52 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_dis_correct_input(char *answer, char *file_disassemble, \
										char *new_filename, t_dis *dis_s)
{
	while (1)
	{
		if (STRINGS_EQU == ft_strequ(answer, "n"))
		{
			ft_printf(FILE_EXIST, file_disassemble);
			ft_bzero(new_filename, ft_strlen(new_filename));
			scanf("%s", new_filename);
		}
		else if (STRINGS_EQU == ft_strequ(answer, "Y"))
		{
			ft_printf("new_filename is [%s.s]\n", new_filename);
			if (dis_s->new_filename != NULL)
				free(dis_s->new_filename);
			dis_s->new_filename = ft_strdup(new_filename);
			if ((open(dis_s->new_filename, O_RDONLY)) >= 0)
				ft_printf(FILE_EXIST, dis_s->new_filename);
//			dis_s->fd_cor = open(new_filename, \
//								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
			break ;
		}
		ft_printf(WRONG_SCANF_INPUT _IS_CORRECT, new_filename);
		ft_bzero(answer, ft_strlen(answer));
		scanf("%s", answer);
	}
}
