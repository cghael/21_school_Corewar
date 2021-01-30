/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:41:18 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

uint8_t	*ft_parse_code(int fd, size_t len)
{
	ssize_t	size;
	uint8_t	*buf;
	uint8_t	byte;

	if (!(buf = ft_memalloc(len)))
		ft_terminate(ERR_DIS_CODE_INIT);
	size = read(fd, buf, len);
	if (size == -1)
		ft_terminate(ERR_DIS_READ_FILE);
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		ft_terminate(ERR_DIS_INVLD_FILE);
	return (buf);
}
