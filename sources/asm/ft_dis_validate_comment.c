/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_validate_comment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:34:31 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:34:31 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_validate_comment(t_dis *dis_s)
{
	size_t		i;

	i = ft_strlen(dis_s->comment);
	while (i < COMMENT_LENGTH)
	{
		if (dis_s->comment[i])
		{
			ft_dis_warning_comment(i);
			return ;
		}
		i++;
	}
}
