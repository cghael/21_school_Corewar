/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_parse_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:21:40 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*ft_dis_parse_string(int fd, size_t len)
{
	ssize_t		size;
	char		*buffer;

	if (!(buffer = ft_strnew(len)))
		ft_dis_error(ERR_MEMALLOC, NULL);
	size = read(fd, buffer, len);
	if (size == -1)
		ft_dis_error(ERR_DIS_READ_FILE, NULL);
	if (size < (ssize_t)len)
		ft_dis_error(ERR_DIS_FILE_SIZE, NULL);
	return (buffer);
}
