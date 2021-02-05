/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_ask_new_filename.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:08:06 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_ask_new_filename(t_dis *dis_s)
{
	if (dis_s->file_s)
	{
		free(dis_s->file_s);
		dis_s->file_s = NULL;
	}
	ft_get_one_line(0, &dis_s->file_s);
	if (EXIT_FAILURE == ft_dis_add_s(dis_s))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
