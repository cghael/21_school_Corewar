/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:36:14 by cghael            #+#    #+#             */
/*   Updated: 2019/10/01 18:05:01 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		len;
	size_t		i;
	size_t		n;

	if (!s1)
		s1 = "\0";
	if (!s2)
		s2 = "\0";
	len = (ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	n = 0;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (len > i)
	{
		while (s1[n] != '\0')
			new[i++] = s1[n++];
		n = 0;
		while (s2[n] != '\0')
			new[i++] = s2[n++];
	}
	if (len == i)
		new[i] = '\0';
	return (new);
}
