/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_parse_int32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:07:43 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int32_t			ft_dis_parse_int32(int fd)
{
	ssize_t		size;
	uint8_t		buffer[4];

	size = read(fd, &buffer, 4);
	if (size == -1)
		ft_dis_error(ERR_DIS_READ_FILE, NULL);
	if (size < 4)
		ft_dis_error(ERR_DIS_FILE_SIZE, NULL);
	return (ft_dis_bytecode_to_int32(buffer, 4));
}
