/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_comment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:51:23 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_validate_comment(t_dis *parser)
{
	size_t i;

	i = ft_strlen(parser->comment);
	while (i < COMMENT_LENGTH)
	{
		if (parser->comment[i])
		{
			ft_comment_warning(i);
			return ;
		}
		i++;
	}
}
