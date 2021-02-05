/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:40:48 by cghael            #+#    #+#             */
/*   Updated: 2019/09/19 17:48:32 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	w_count;

	if (!s || !*s)
		return (0);
	i = 1;
	w_count = 0;
	if (s[0] && s[0] != c)
		w_count++;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c))
			w_count++;
		i++;
	}
	return (w_count);
}
