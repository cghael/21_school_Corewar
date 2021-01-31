/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_warning_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:53:12 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:53:13 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_warning_comment(size_t pos)
{
	size_t		prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4;
	ft_dprintf(STDERR_FILENO, WARN_DIS);
	ft_dprintf(STDERR_FILENO, WARN_DIS_COMM, prefix + pos + 1);
}
