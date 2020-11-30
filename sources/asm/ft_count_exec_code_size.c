//
// Created by Cora Ghael on 11/30/20.
//
#include "asm.h"

void			ft_count_exec_code_size(t_asm *asm_s)
{
	int i;

	i = 0;
	asm_s->exec_size += 1 + g_ops[asm_s->op_list->last->num].is_args_type;
	while (i < g_ops[asm_s->op_list->last->num].n_args)
	{
		if (asm_s->op_list->last->args[i].type == DIR_CODE)
			asm_s->exec_size += \
							(int)g_ops[asm_s->op_list->last->num].t_dir_size;
		else if (asm_s->op_list->last->args[i].type == REG_CODE)
			asm_s->exec_size += 1;
		else if (asm_s->op_list->last->args[i].type == IND_CODE)
			asm_s->exec_size += 2;
		i++;
	}
}
