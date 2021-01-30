/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:43:04 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:43:05 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_parse_str(int fd, size_t len)
{
	ssize_t	size;
	char	*buffer;

	if (!(buffer = ft_strnew(len)))
		ft_terminate(ERR_STR_INIT);
	size = read(fd, buffer, len);
	if (size == -1)
		ft_terminate(ERR_READ_FILE);
	if (size < (ssize_t)len)
		ft_terminate(ERR_INVALID_FILE);
	return (buffer);
}
