/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_of_whitespaces_or_comment.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:37:28 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:37:29 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_line_of_whitespaces_or_comment(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (asm_s->parse->line[asm_s->pos] == COMMENT_CHAR\
		|| asm_s->parse->line[asm_s->pos] == ALT_COMMENT_CHAR)
			return (EXIT_SUCCESS);
		if (ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			return (EXIT_FAILURE);
		asm_s->pos++;
	}
	return (EXIT_SUCCESS);
}
