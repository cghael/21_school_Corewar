//
// Created by  Anton Gorobets on 21.10.2020.
//

#include "asm.h"

static int	ft_find_name_in_line(t_asm *asm_s, int *i)
{
	while (asm_s->parse->line[*i])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[*i]))
			(*i)++;
		else if (ft_strlen(asm_s->parse->line + *i) < 5 \
		|| ft_strncmp(asm_s->parse->line + *i, NAME_CMD_STRING, 5))
			return (EXIT_FAILURE);
		else
		{
			*i += ft_strlen(NAME_CMD_STRING);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

static int	ft_find_comment_in_line(t_asm *asm_s, int *i)
{
	while (asm_s->parse->line[*i])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[*i]))
			(*i)++;
		else if (ft_strlen(asm_s->parse->line + *i) < 8 \
		|| ft_strncmp(asm_s->parse->line + *i, COMMENT_CMD_STRING, 8))
			return (EXIT_FAILURE);
		else
		{
			*i += ft_strlen(NAME_CMD_STRING);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

int			ft_start_check_name_or_comment(t_asm *asm_s)
{
	int		i;

	i = 0;
	if (EXIT_SUCCESS == ft_line_of_whitespaces_or_comment(asm_s))
		return (EXIT_SUCCESS);
	if (EXIT_SUCCESS == ft_find_name_in_line(asm_s, &i))
	{
		ft_check_quotes(asm_s, &i, NAME_START);
		return ();
	}
	i = 0;
	if (EXIT_SUCCESS == ft_find_comment_in_line(asm_s, &i))
	{
		ft_check_quotes(asm_s, &i, CMT_START);
		return ();
	}
	//todo error position
	return (EXIT_FAILURE);
}
