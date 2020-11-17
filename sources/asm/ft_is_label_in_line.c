//
// Created by Cora Ghael on 11/17/20.
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

int			ft_is_label_in_line(t_asm *asm_s, const char *colon)
{
	int		pos;

	pos = (int)(colon - asm_s->parse->line);
	if (EXIT_SUCCESS == ft_is_label_char(asm_s->parse->line[pos - 1]))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
