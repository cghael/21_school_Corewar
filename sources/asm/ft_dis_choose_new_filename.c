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
	int			check_file;

	new_filename = ft_strnew(0);
	answer = ft_strnew(0);
	if (!new_filename || !answer)
	{
		if (new_filename != NULL)
		{
			free(new_filename);
			new_filename = NULL;
		}
		if (answer != NULL)
		{
			free(answer);
			answer = NULL;
		}
		return (ft_dis_error(ERR_DIS_CHOOSE, NULL));
	}
	check_file = ft_dis_check_file_exist(dis_s->file_s);
	while (FILE_EXIST == check_file)
	{
		/*
		 * Проверяем, что файл по-умолчанию можно создать.
		 * Если нет - просим имя файла.
		 *
		 * пока файл уже ЕСТЬ в системе и он открывается:
		 * 		(1) просим указать новое имя файла
		 */
		ft_printf(FILE_EXIST_TXT, dis_s->file_s);
		new_filename = ft_dis_ask_new_filename(new_filename, dis_s);
		while (FILE_EXIST == ft_dis_check_file_exist(new_filename))
		{
			ft_printf(FILE_EXIST_TXT, new_filename);
			new_filename = ft_dis_ask_new_filename(new_filename, dis_s);
		}

		ft_dprintf(2, "STOP! << all working to here line>> \n");//todo right ++ NULL protect
		/*
		* 			добавляем к имени .s
		* 			(2) Спрашиваем, такое ли имя хотим
		* 				Да - сохраняем имя в структуру
		* 				Нет - (1)
		* 				ошибочный ввод - Варнинг что ошибочный ввод - (2)
		*
	   */
//		if (YES == ft_dis_answer())
//		{
//			if (EXIT_FAILURE == ft_dis_try_get_fd())
//			{
//				while ()
//			}
//		}


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
