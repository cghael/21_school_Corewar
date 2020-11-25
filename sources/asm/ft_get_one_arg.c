//
// Created by Cora Ghael on 11/25/20.
//
#include "asm.h"

static int			ft_parse_reg(t_asm *asm_s, int arg_pars)
{
	if (asm_s->op_list->last->args[arg_pars].type != REG \
	&& asm_s->op_list->last->args[arg_pars].type != REG_DIR \
	&& asm_s->op_list->last->args[arg_pars].type != REG_DIR_IND)
	{
		asm_s->parse->err_num = WRONG_ARG_TYPE;
		return (EXIT_FAILURE);
	}
	asm_s->pos++;
	if (asm_s->parse->line[asm_s->pos] < 49 \
	|| asm_s->parse->line[asm_s->pos] > 59)
	{
		asm_s->parse->err_num = INCORRECT_REG;
		return (EXIT_FAILURE);
	}
}

int					ft_get_one_arg(t_asm *asm_s, int arg_pars)
{
	if (asm_s->parse->line[asm_s->pos] == 'r')
	{
		if (EXIT_FAILURE == ft_parse_reg(asm_s, arg_pars))
		{
			//add error
			return (EXIT_FAILURE);
		}
	}
	else if (asm_s->parse->line[asm_s->pos] == '%')
	{
		if (EXIT_FAILURE == ft_parse_direct(asm_s, arg_pars))
		{
			//add error
			return (EXIT_FAILURE);
		}
	}
	else
	{
		if (EXIT_FAILURE == ft_parse_ind(asm_s, arg_pars))
		{
			//add error
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
