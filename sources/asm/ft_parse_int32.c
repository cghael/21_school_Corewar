/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:42:31 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:42:33 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int32_t	ft_parse_int32(int fd)
{
	ssize_t	size;
	uint8_t	buffer[4];

	size = read(fd, &buffer, 4);
	if (size == -1)
		ft_terminate(ERR_READ_FILE);
	if (size < 4)
		ft_terminate(ERR_INVALID_FILE);
	return (ft_bytecode_to_int32(buffer, 4));
}
