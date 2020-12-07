/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_valide_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:27:43 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 12:27:48 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_valide_comment(t_dis *dis_s)
{
	size_t		i;

	i = ft_strlen(dis_s->comment);
	while (i < COMMENT_LENGTH)
	{
		if (dis_s->comment[i])
		{
			ft_dis_error(ERR_DIS_COMMENT, NULL);
			return ;
		}
		i++;
	}
}
