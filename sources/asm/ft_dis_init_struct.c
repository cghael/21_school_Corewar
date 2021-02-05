/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_init_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:19:20 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_dis		*ft_dis_init_struct(char *file_cor)
{
	t_dis	*dis_s;

	if (!(dis_s = ft_memalloc(sizeof(t_dis))))
	{
		ft_dis_error_free_dis_s(ERR_MEMALLOC, NULL, dis_s);
		return (NULL);
	}
	dis_s->fd_s = -1;
	dis_s->file_s = NULL;
	if ((dis_s->fd_cor = open(file_cor, O_RDONLY)) < 1)
		ft_dis_error_free_dis_s(ERR_DIS_READ_FILE, NULL, dis_s);
	dis_s->name = NULL;
	dis_s->comment = NULL;
	dis_s->code_size = 0;
	dis_s->code = NULL;
	dis_s->pos = 0;
	dis_s->elems = NULL;
	return (dis_s);
}
