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

	dis_s->file_s = ft_strnew(0);
	answer = ft_strnew(0);
	if (!dis_s->file_s || !answer)
	{
		if (dis_s->file_s != NULL)
		{
			free(dis_s->file_s);
			dis_s->file_s = NULL;
		}
		if (answer != NULL)
		{
			free(answer);
			answer = NULL;
		}
		return (ft_dis_error(ERR_DIS_CHOOSE, NULL));
	}
	ft_dprintf(2, " (1) FD [%d] dis_file_s [%s]\n"
				  "STOP! << all working to here line>> \n", dis_s->fd_cor, dis_s->file_s);//todo right ++ NULL protect
	if (FILE_EXIST == ft_dis_check_file_correct(dis_s) || dis_s->fd_cor < 0)
	{
		/*
		 * Проверяем, что файл по-умолчанию можно создать.
		 * Если нет - просим имя файла.
		 *
		 * пока файл уже ЕСТЬ в системе и он открывается:
		 * 		(1) просим указать новое имя файла
		* 			добавляем к имени .s
		 */
		ft_printf(FILE_EXIST_TXT FILE_INPUT_NEW, dis_s->file_s);
		ft_dis_ask_new_filename(dis_s);
		while (dis_s->fd_cor < 0)
//		while (FILE_EXIST == ft_dis_check_file_correct(dis_s) || dis_s->fd_cor < 0)
		{
			ft_printf(FILE_EXIST_TXT FILE_INPUT_NEW, dis_s);
			ft_dis_ask_new_filename(dis_s);
			if (FILE_NOT_EXIST == ft_dis_check_file_correct(dis_s))
			{
				ft_strdel(&dis_s->file_s);
				dis_s->file_s = ft_strdup(dis_s->file_s);//todo protect
				if (EXIT_FAILURE == ft_dis_try_create_file(dis_s))
					ft_printf("Srry, incorrect filename! [%d]\n", dis_s->fd_cor);
				else
					break;
			}
		}
	}
		ft_dprintf(2, "dis_file_s [%s]\n"
				"STOP! << all working to here line>> \n", dis_s->file_s);//todo right ++ NULL protect
		/*
		* 			(2) Спрашиваем, такое ли имя хотим
		* 				Да - сохраняем имя в структуру
		* 				Нет - (1)
		* 				ошибочный ввод - Варнинг что ошибочный ввод - (2)
		*
	   */

	ft_printf("Ok! I save file to [%s]\n",dis_s->file_s);//todo del
	return (EXIT_SUCCESS);
}
