//
// Created by  Anton Gorobets on 21.10.2020.
//
#include "asm.h"

int			ft_line_of_whitespaces_or_comment(t_asm *asm_s)
{
	int		i;

	i = 0;
	while (asm_s->parse->line[i])
	{
		if (asm_s->parse->line[i] == '#')
			return (EXIT_SUCCESS);
		if (ft_is_whitespace(asm_s->parse->line[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
