//
// Created by  Anton Gorobets on 23.12.2020.
//
#include "asm.h"

int			ft_create_arg_content(t_asm *asm_s, int arg_pars, int size)
{
	int		num;

	asm_s->op_list->last->args[arg_pars].content = ft_memalloc(sizeof(char) * size);
	if (asm_s->op_list->last->args[arg_pars].content == NULL)
		return (EXIT_FAILURE);
	num = ft_atoi(&asm_s->parse->line[asm_s->pos]);
	ft_int32_to_bytecode(asm_s->op_list->last->args[arg_pars].content, 0, num, size);
	return (EXIT_SUCCESS);
}
