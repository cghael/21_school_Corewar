/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:05:26 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_check_quotes(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		else if (asm_s->parse->line[asm_s->pos] == '"')
		{
			asm_s->pos++;
			return (ft_open_quotes_processing(asm_s));
		}
		else
		{
			asm_s->parse->err_num = SYNTAX_ERROR;
			return (EXIT_FAILURE);
		}
	}
	asm_s->parse->err_num = SYNTAX_ERROR;
	return (EXIT_FAILURE);
}
