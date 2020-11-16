//
// Created by  Anton Gorobets on 21.10.2020.
//

#include "asm.h"

static int	ft_find_name_in_line(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		else if (ft_strlen(asm_s->parse->line + asm_s->pos) < 5 \
		|| ft_strncmp(asm_s->parse->line + asm_s->pos, NAME_CMD_STRING, 5))
			return (EXIT_FAILURE);
		else
		{
			asm_s->pos += ft_strlen(NAME_CMD_STRING);
			asm_s->quotes = NAME_START;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

static int	ft_find_comment_in_line(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		else if (ft_strlen(asm_s->parse->line + asm_s->pos) < 8 \
		|| ft_strncmp(asm_s->parse->line + asm_s->pos, COMMENT_CMD_STRING, 8))
			return (EXIT_FAILURE);
		else
		{
			asm_s->pos += ft_strlen(COMMENT_CMD_STRING);
			asm_s->quotes = CMT_START;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

int			ft_start_check_name_or_comment(t_asm *asm_s)
{
	int		res;

	if (EXIT_SUCCESS == ft_line_of_whitespaces_or_comment(asm_s))
	{
		return (EXIT_SUCCESS);
	}
	if (EXIT_SUCCESS == ft_find_name_in_line(asm_s))
	{
		res = ft_check_quotes(asm_s);
		return (res);
	}
	asm_s->pos = 0;
	if (EXIT_SUCCESS == ft_find_comment_in_line(asm_s))
	{
		res = ft_check_quotes(asm_s);
		return (res);
	}
	//todo error position
	return (EXIT_FAILURE);
}
