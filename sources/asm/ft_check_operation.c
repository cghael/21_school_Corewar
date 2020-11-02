//
// Created by  Anton Gorobets on 02.11.2020.
//
#include "asm.h"

int		ft_check_operation(t_asm *asm_s)
{
	asm_s->pos = 0;
	if (ft_line_of_whitespaces_or_comment(asm_s, asm_s->pos))
		return (EXIT_SUCCESS);
	//is label
	//is operation
	return (EXIT_SUCCESS);
}
