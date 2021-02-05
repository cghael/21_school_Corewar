/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_copy_filename.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:42:23 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 13:42:26 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_dis_copy_filename(char *filename, t_dis *dis_s)
{
	char	*tmp;

	if (dis_s->file_s)
	{
		free(dis_s->file_s);
		dis_s->file_s = NULL;
	}
	if (!(tmp = ft_strnew(1)))
		return (EXIT_FAILURE);
	if (!(dis_s->file_s = ft_strjoin(tmp, filename)))
	{
		free(tmp);
		return (EXIT_FAILURE);
	}
	free(tmp);
	return (EXIT_SUCCESS);
}
