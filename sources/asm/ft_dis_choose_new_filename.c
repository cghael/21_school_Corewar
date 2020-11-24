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

int ft_dis_choose_new_filename(t_dis *dis_s)
{
	char		*answer;
	char		*new_filename;

	new_filename = ft_strnew(0);
	answer = ft_strnew(0);
	if (!new_filename || !answer)
	{
		if (new_filename != NULL)
			free(new_filename);
		if (answer != NULL)
			free(answer);
		return (ft_dis_error(ERR_DIS_CHOOSE, NULL));
	}

//	if (!(dis_s->file_s = ft_strjoin(dis_s->file_s, ".s")))
//		ft_dis_error(ERR_DIS_CHOOSE, dis_s->file_s);
	while (FILE_EXIST == ft_dis_check_file_exist(dis_s->file_s))
	{
		scanf("%s", new_filename);
		if (!(new_filename = ft_strjoin(new_filename, ".s")))
			return (ft_dis_error(ERR_DIS_CHOOSE, new_filename));
		while (STRINGS_EQU != ft_strequ(answer, "Y"))
		{
			ft_printf(Q_CORRECT_NAME, new_filename);
			scanf("%s", answer);
			ft_dis_correct_input(answer, new_filename, dis_s);
		}
	}
	ft_printf("Ok! I save file to [%s]\n",dis_s->file_s);//todo del
//	dis_s->file_s = ft_strdup(file_s);//todo kek?
	return (EXIT_SUCCESS);
}
