/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_label_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:32:01 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_is_label_char(char ch)
{
	int		i;
	char	str[] = LABEL_CHARS;

	i = 0;
	while (str[i])
	{
		if (ch == str[i])
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}
