/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label_processing_n_pos_update.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:32:35 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:56:53 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			ft_is_label_in_line(t_asm *asm_s, const char *colon)
{
	int		pos;

	pos = (int)(colon - asm_s->parse->line);
	if (EXIT_SUCCESS == ft_is_label_char(asm_s->parse->line[pos - 1]))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int			ft_error_label_name(t_asm *asm_s, int pos, t_errors error)
{
	asm_s->parse->err_num = error;
	asm_s->pos = pos;
	return (EXIT_FAILURE);
}

static int			ft_is_mention(t_asm *asm_s, const char *colon, int *pos)
{
	int		i;

	*pos = (int)(colon - asm_s->parse->line);
	if (EXIT_FAILURE == ft_is_whitespace(asm_s->parse->line[*pos - 1]) \
	&& asm_s->parse->line[*pos - 1] != DIRECT_CHAR \
	&& asm_s->parse->line[*pos - 1] != SEPARATOR_CHAR)
		return (ft_error_label_name(asm_s, *pos - 1, LEXICAL_ERROR));
	i = *pos + 1;
	while (asm_s->parse->line[i] && \
	EXIT_FAILURE == ft_is_whitespace(asm_s->parse->line[i]) \
	&& asm_s->parse->line[i] != SEPARATOR_CHAR \
	&& asm_s->parse->line[i] != COMMENT_CHAR \
	&& asm_s->parse->line[i] != ALT_COMMENT_CHAR)
	{
		if (EXIT_FAILURE == ft_is_label_char(asm_s->parse->line[i]))
			return (ft_error_label_name(asm_s, i, LEXICAL_ERROR));
		i++;
	}
	*pos = i;
	return (EXIT_SUCCESS);
}

static int			ft_check_comment_pos(char *colon, char *line, int pos)
{
	char *comment;

	comment = ft_strchr(&line[pos], COMMENT_CHAR);
	if (comment && colon > comment)
		return (EXIT_FAILURE);
	comment = ft_strchr(&line[pos], ALT_COMMENT_CHAR);
	if (comment && colon > comment)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int					ft_label_processing_n_pos_update(t_asm *asm_s, int pos)
{
	char	*colon;

	while ((colon = ft_strchr(&asm_s->parse->line[pos], LABEL_CHAR)) != NULL\
	&& EXIT_SUCCESS == ft_check_comment_pos(colon, asm_s->parse->line, pos))
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[pos]))
		{
			asm_s->pos++;
			pos++;
		}
		else if (EXIT_SUCCESS == ft_is_label_in_line(asm_s, colon))
		{
			if (asm_s->labels \
			&& asm_s->labels->last->n_line == asm_s->parse->n_line)
				return (ft_error_label_name(asm_s, asm_s->pos, \
														TOO_MATCH_LABELS));
			else if (EXIT_FAILURE == ft_label_saving_n_pos_update(asm_s, colon))
				return (EXIT_FAILURE);
			pos = asm_s->pos;
		}
		else if (EXIT_FAILURE == ft_is_mention(asm_s, colon, &pos))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
