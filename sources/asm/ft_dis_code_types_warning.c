/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_code_types_warning.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:39:30 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:39:31 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_code_types_warning(size_t pos)
{
	size_t		prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(STDERR_FILENO, WARN_DIS);
	ft_dprintf(STDERR_FILENO, WARN_DIS_CODE_TYP1);
	ft_dprintf(STDERR_FILENO, WARN_DIS_CODE_TYP2, prefix + pos + 1);
}
