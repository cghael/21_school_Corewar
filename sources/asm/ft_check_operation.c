//
// Created by  Anton Gorobets on 02.11.2020.
//
#include "asm.h"

int		ft_check_operation(t_asm *asm_s)
{
	if (EXIT_SUCCESS == ft_line_of_whitespaces_or_comment(asm_s))
	{
		asm_s->parse->free_line = TRUE;
		return (EXIT_SUCCESS);
	}
	asm_s->pos = 0;
	//is label
	//is operation
	return (EXIT_SUCCESS);
}
