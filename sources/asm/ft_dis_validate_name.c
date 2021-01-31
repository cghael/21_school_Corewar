/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_validate_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:32:08 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:32:08 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_validate_name(t_dis *dis_s)
{
	size_t		i;

	i = ft_strlen(dis_s->name);
	while (i < PROG_NAME_LENGTH)
	{
		if (dis_s->name[i])
		{
			ft_dis_warning_name(i);
			return ;
		}
		i++;
	}
}
