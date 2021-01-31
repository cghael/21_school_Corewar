/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_warning_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:52:22 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:52:23 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_warning_name(size_t pos)
{
	size_t		prefix;

	prefix = 4;
	ft_dprintf(STDERR_FILENO, WARN_DIS);
	ft_dprintf(STDERR_FILENO, WARN_DIS_NAME, prefix + pos + 1);
}
