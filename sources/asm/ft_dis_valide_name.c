/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_valide_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:53:48 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 11:53:52 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_valide_name(t_dis *dis_s)
{
	size_t		i;

	i = ft_strlen(dis_s->name);
	while (i < PROG_NAME_LENGTH)
	{
		if (dis_s->name[i])
		{
			ft_dis_error(ERR_DIS_NAME, NULL);
			return ;
		}
		i++;
	}
}
