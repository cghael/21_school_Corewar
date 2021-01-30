/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_label_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:32:01 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 15:03:08 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*ft_create_label_chars_str()
{
	char *str;

	str = ft_memalloc(ft_strlen(LABEL_CHARS) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, LABEL_CHARS);
	return (str);
}

int			ft_is_label_char(char ch)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_create_label_chars_str();
	if (str == NULL)
		return (EXIT_FAILURE);
	while (str[i])
	{
		if (ch == str[i])
		{
			free(str);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free(str);
	return (EXIT_FAILURE);
}
