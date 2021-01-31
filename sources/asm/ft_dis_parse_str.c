/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_parse_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:29:06 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:29:07 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*ft_dis_parse_str(int fd, size_t len)
{
	ssize_t		size;
	char		*buf;

	if (!(buf = ft_strnew(len)))
		ft_dis_terminate(ERR_DIS_STR_INIT);
	size = read(fd, buf, len);
	if (size == -1)
		ft_dis_terminate(ERR_DIS_READ_FILE);
	if (size < (ssize_t)len)
		ft_dis_terminate(ERR_DIS_INVLD_FILE);
	return (buf);
}
