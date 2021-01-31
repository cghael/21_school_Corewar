/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_op_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:25:47 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 17:25:50 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*ft_create_op_chars_str(void)
{
	char *str;

	str = ft_memalloc(ft_strlen(OP_CHARS) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, OP_CHARS);
	return (str);
}

int			ft_is_op_char(char ch)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_create_op_chars_str();
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
