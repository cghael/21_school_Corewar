/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_parse_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:30:13 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:30:14 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

uint8_t			*ft_dis_parse_code(int fd, size_t len)
{
	ssize_t		size;
	uint8_t		*buf;
	uint8_t		byte;

	if (!(buf = ft_memalloc(len)))
		return (NULL);
	size = read(fd, buf, len);
	if (size == -1)
		return (NULL);
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		return (NULL);
	return (buf);
}
