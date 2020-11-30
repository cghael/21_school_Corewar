//
// Created by Cora Ghael on 11/30/20.
//
#include "asm.h"

int				ft_write_arg_type_code(t_asm *asm_s)
{
	int		shift;
	int		i;

	if (g_ops[asm_s->op_list->last->num].is_args_type == FALSE)
		return (EXIT_SUCCESS);
	shift = 6;
	i = 0;
	while (i < g_ops[asm_s->op_list->last->num].n_args)
	{
		asm_s->op_list->last->args_code += \
									asm_s->op_list->last->args[i].type << shift;
		shift -= 2;
		i++;
	}
	return (EXIT_SUCCESS);
}
