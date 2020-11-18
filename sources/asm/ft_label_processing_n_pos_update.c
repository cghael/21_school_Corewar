//
// Created by Cora Ghael on 11/18/20.
//
#include "asm.h"

static int			ft_is_label_char(char ch)
{
	int		i;
	char	str[] = LABEL_CHARS;

	i = 0;
	while (str[i])
	{
		if (ch == str[i])
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

static int			ft_is_label_in_line(t_asm *asm_s, const char *colon)
{
	int		pos;

	pos = (int)(colon - asm_s->parse->line);
	if (EXIT_SUCCESS == ft_is_label_char(asm_s->parse->line[pos - 1]))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int			ft_is_mention(t_asm *asm_s, const char *colon, int *pos)
{
	*pos = (int)(colon - asm_s->parse->line);
	if (EXIT_FAILURE == ft_is_whitespace(asm_s->parse->line[*pos - 1]) \
	&& asm_s->parse->line[*pos - 1] != DIRECT_CHAR \
	&& asm_s->parse->line[*pos - 1] != SEPARATOR_CHAR)
		return (EXIT_FAILURE);
	if (EXIT_FAILURE == ft_is_label_char(asm_s->parse->line[*pos + 1]))
	{
		asm_s->parse->err_num = LEXICAL_ERROR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int					ft_label_processing_n_pos_update(t_asm *asm_s)
{
	char	*colon;
	int		pos;

	pos = asm_s->pos;
	while ((colon = ft_strchr(&asm_s->parse->line[pos], LABEL_CHAR)) != NULL)
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[pos]))
			asm_s->pos++;
		else if (EXIT_SUCCESS == ft_is_label_in_line(asm_s, colon))
		{
			if (asm_s->tokens && asm_s->tokens->last->typo == LABEL \
			&& asm_s->tokens->last->n_line == asm_s->parse->n_line)
			{
				asm_s->parse->err_num = TOO_MATCH_LABELS;
				return (EXIT_FAILURE);
			}
			else
				ft_label_saving_n_pos_update(asm_s, colon);
		}
		else if (EXIT_FAILURE == ft_is_mention(asm_s, colon, &pos))
			return (EXIT_FAILURE);
		pos = asm_s->pos;
	}
	return (EXIT_SUCCESS);
}
