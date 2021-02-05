/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:41:43 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:41:45 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_parsing_processing(t_asm *asm_s)
{
	ft_parse_line(asm_s);
	while (asm_s->parse->res > 0)
	{
		asm_s->parse->is_whitespace = FALSE;
		if (EXIT_FAILURE == ft_line_data_processing(asm_s))
		{
			ft_asm_error_in_line(asm_s);
			return (PARSING_ERR);
		}
		if (asm_s->parse->line)
		{
			free(asm_s->parse->line);
			asm_s->parse->line = NULL;
		}
		ft_parse_line(asm_s);
	}
	if (asm_s->parse->res < 0)
		return (PARSING_ERR);
	return (PARSING_OK);
}

int				ft_parse_file(t_asm *asm_s)
{
	if (EXIT_FAILURE == ft_check_end_newline(asm_s))
		return (PARSING_ERR);
	if (PARSING_ERR == ft_parsing_processing(asm_s))
		return (PARSING_ERR);
	if (asm_s->parse->res == 0 \
	&& asm_s->parse->endline == TRUE \
	&& asm_s->parse->is_whitespace == FALSE)
	{
		asm_s->parse->err_num = NO_NEWLINE;
		ft_asm_error_in_line(asm_s);
		return (PARSING_ERR);
	}
	if (EXIT_FAILURE == ft_transform_mentions(asm_s))
	{
		asm_s->parse->err_num = NO_SUCH_LABEL;
		ft_asm_error_no_label(asm_s);
		return (PARSING_ERR);
	}
	if (EXIT_FAILURE == ft_write_exec_code_in_line(asm_s))
		return (PARSING_ERR);
	return (PARSING_OK);
}
