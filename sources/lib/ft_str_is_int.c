/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:47:00 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 14:47:03 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_int(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	if (i < 10)
		return (1);
	else if (i > 11 || (i > 10 && (str[0] != '-' && str[0] != '+')))
		return (0);
	if (str[0] == '-' && ft_strncmp("2147483648", &str[1], 10) < 0)
		return (0);
	if (str[0] == '+' && ft_strncmp("2147483647", &str[1], 10) < 0)
		return (0);
	if (ft_strncmp("2147483647", &str[0], 10) < 0)
		return (0);
	return (1);
}
