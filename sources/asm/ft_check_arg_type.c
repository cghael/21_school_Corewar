//
// Created by Cora Ghael on 11/27/20.
//
#include "asm.h"

static int	ft_check_reg_arg(t_asm *asm_s, int arg_pars)
{
	if (g_ops[asm_s->op_list->last->num].args[arg_pars] != REG \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_DIR \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_IND \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_DIR_IND)
	{
		asm_s->parse->err_num = WRONG_ARG_TYPE;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_ind_arg(t_asm *asm_s, int arg_pars)
{
	if (g_ops[asm_s->op_list->last->num].args[arg_pars] != IND \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_IND \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != DIR_IND \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_DIR_IND)
	{
		asm_s->parse->err_num = WRONG_ARG_TYPE;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_dir_arg(t_asm *asm_s, int arg_pars)
{
	if (g_ops[asm_s->op_list->last->num].args[arg_pars] != DIR \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_DIR \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != DIR_IND \
		&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_DIR_IND)
	{
		asm_s->parse->err_num = WRONG_ARG_TYPE;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			ft_check_arg_type(t_asm *asm_s, int type, int arg_pars)
{
	if (type == T_REG)
	{
		if (EXIT_FAILURE == ft_check_reg_arg(asm_s, arg_pars))
			return (EXIT_FAILURE);
	}
	else if (type == T_DIR)
	{
		if (EXIT_FAILURE == ft_check_dir_arg(asm_s, arg_pars))
			return (EXIT_FAILURE);
	}
	else if (type == T_IND)
	{
		if (EXIT_FAILURE == ft_check_ind_arg(asm_s, arg_pars))
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	asm_s->pos++;
	return (EXIT_SUCCESS);
}
