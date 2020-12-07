/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_parse_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:43:03 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 13:43:04 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

uint8_t			*ft_dis_parse_code(int fd, size_t len)
{
	ssize_t		size;
	uint8_t		*buffer;
	uint8_t		byte;

	if (!(buffer = ft_memalloc(len)))
		ft_dis_error(ERR_MEMALLOC, NULL);
	size = read(fd, buffer, len);
	if (size == -1)
		ft_dis_error(ERR_DIS_READ_FILE, NULL);
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		ft_dis_error(ERR_DIS_FILE_SIZE, NULL);
	return (buffer);
}
