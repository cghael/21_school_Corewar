/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:51:40 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:51:42 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_validate_name(t_dis *parser)
{
	size_t i;

	i = ft_strlen(parser->name);
	while (i < PROG_NAME_LENGTH)
	{
		if (parser->name[i])
		{
			ft_name_warning(i);
			return ;
		}
		i++;
	}
}
