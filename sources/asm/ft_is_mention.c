//
// Created by Cora Ghael on 11/17/20.
//
#include "asm.h"

int			ft_is_mention(t_asm *asm_s, const char *colon, int *pos)
{
	*pos = (int)(colon - asm_s->parse->line);
	if (EXIT_FAILURE == ft_is_whitespace(asm_s->parse->line[*pos - 1]) \
	&& asm_s->parse->line[*pos - 1] != DIRECT_CHAR \
	&& asm_s->parse->line[*pos - 1] != SEPARATOR_CHAR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
