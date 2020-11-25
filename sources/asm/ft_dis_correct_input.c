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

int ft_dis_correct_input(char *answer, char *new_filename, t_dis *dis_s)
{
	ft_dprintf(2,"DIS_CORR_START ANSWER [%s]\n", answer);//todo del
	while (1)
	{
		ft_printf("\nDDDDDDDDDDD %s\n", answer);//todo del
		if (STRINGS_EQU == ft_strequ(answer, "n"))
		{
			ft_printf(FILE_EXIST_TXT, dis_s->file_s);
			ft_bzero(new_filename, ft_strlen(new_filename));
			scanf("%s", new_filename);
			if (!(new_filename = ft_strjoin(new_filename, ".s")))
				return (ft_dis_error(ERR_DIS_CHOOSE, new_filename));
		}
		else if (STRINGS_EQU == ft_strequ(answer, "Y"))
		{
			ft_printf(FILE_NOT_EXIST_TXT, new_filename);//todo right 1st Y
			if (dis_s->file_s != NULL)
				free(dis_s->file_s);
			dis_s->file_s = ft_strdup(new_filename);
			ft_printf("\ndis_s->file_s [%s]\n", dis_s->file_s);//todo del
			if (FILE_NOT_EXIST == ft_dis_check_file_exist(dis_s->file_s))
				return (EXIT_SUCCESS);
//				break ;
//			else
//				ft_printf(FILE_EXIST_TXT, dis_s->file_s);
		}
//		ft_printf(WRONG_SCANF_INPUT _IS_CORRECT, new_filename);
		ft_bzero(answer, ft_strlen(answer));
		scanf("%s", answer);
	}
	return (EXIT_SUCCESS);
}
