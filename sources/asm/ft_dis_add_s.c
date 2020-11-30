/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_add_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:45:17 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 13:45:20 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_add_s(t_dis *dis_s)
{
	if (!(dis_s->file_s = ft_strjoin(dis_s->file_s, ".s")))
		return (ft_dis_error(ERR_DIS_CHOOSE, dis_s->file_s));
	return (EXIT_SUCCESS);
}
