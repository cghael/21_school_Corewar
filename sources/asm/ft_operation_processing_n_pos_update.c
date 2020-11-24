//
// Created by Cora Ghael on 11/17/20.
//
#include "asm.h"

static int		ft_is_valid_op(t_asm *asm_s)
{
	int		i;

	i = 16;
	while (i)
	{
		if (ft_strncmp(g_ops[i].name, &asm_s->parse->line[asm_s->pos], ft_strlen(g_ops[i].name)) == 0)
			return (EXIT_SUCCESS);
		i--;
	}
	return (EXIT_FAILURE);
}

int				ft_operation_processing_n_pos_update(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		if (asm_s->parse->line[asm_s->pos] == '#')
			return (EXIT_SUCCESS);
		if (EXIT_FAILURE == ft_is_valid_op(asm_s))
			return (EXIT_FAILURE);
	}
	//while (skip whitespaces) - done!
	//is operator and valid
		//arg type
		//arg value
		//separator?
	//count arg type code
	return (EXIT_SUCCESS);
}
