/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_del_cor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:56:47 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 13:56:50 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_del_cor(t_dis *dis_s)
{
	char		*dot;
	char		*tmp;

	tmp = dis_s->file_s;
	if (!(dot = ft_strrchr(dis_s->file_s, '.')) ||
		!(dis_s->file_s = ft_strsub(tmp, 0, dot - dis_s->file_s)))
		return (ft_dis_error_free(ERR_DIS_FILE, dis_s->file_s, dis_s));
	free(tmp);
	return (EXIT_SUCCESS);
}
