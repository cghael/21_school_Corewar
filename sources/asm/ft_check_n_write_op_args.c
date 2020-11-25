//
// Created by Cora Ghael on 11/24/20.
//
#include "asm.h"

int			ft_check_n_write_op_args(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		else
		{
			//is LABEL_CHAR && LABEL_CHARS
			//is DIRECT_CHAR
			//is SEPARATOR_CHAR
			//is 'r'
			//is number
			//is COMMENT_CHAR || ALT_COMMENT_CHAR
		}
	}
	//move pos
	return (EXIT_SUCCESS);
}
