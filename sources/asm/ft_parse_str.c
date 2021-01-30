/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:43:04 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_parse_str(int fd, size_t len)
{
	ssize_t	size;
	char	*buf;

	if (!(buf = ft_strnew(len)))
		ft_terminate(ERR_DIS_STR_INIT);
	size = read(fd, buf, len);
	if (size == -1)
		ft_terminate(ERR_DIS_READ_FILE);
	if (size < (ssize_t)len)
		ft_terminate(ERR_DIS_INVLD_FILE);
	return (buf);
}
