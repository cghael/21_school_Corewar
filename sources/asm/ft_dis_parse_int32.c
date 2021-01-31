/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_parse_int32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:26:06 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:26:07 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int32_t			ft_dis_parse_int32(int fd)
{
	ssize_t		size;
	uint8_t		buf[4];

	size = read(fd, &buf, 4);
	if (size == -1)
		ft_dis_terminate(ERR_DIS_READ_FILE);
	if (size < 4)
		ft_dis_terminate(ERR_DIS_INVLD_FILE);
	return (ft_dis_bytecode_to_int32(buf, 4));
}
