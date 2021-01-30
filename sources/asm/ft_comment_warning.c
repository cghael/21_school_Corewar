/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment_warning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:17:01 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_comment_warning(size_t pos)
{
	size_t prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4;
	ft_dprintf(2, "Warning: Comment was completed with not null bytes"\
												" — [%zu]\n", prefix + pos + 1);
}
