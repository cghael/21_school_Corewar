/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:42:31 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int32_t	ft_parse_int32(int fd)
{
	ssize_t	size;
	uint8_t	buf[4];

	size = read(fd, &buf, 4);
	if (size == -1)
		ft_terminate(ERR_DIS_READ_FILE);
	if (size < 4)
		ft_terminate(ERR_DIS_INVLD_FILE);
	return (ft_bytecode_to_int32(buf, 4));
}
