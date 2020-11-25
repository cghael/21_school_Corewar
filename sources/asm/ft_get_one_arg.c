//
// Created by Cora Ghael on 11/25/20.
//
#include "asm.h"

static char			*ft_get_content(t_asm *asm_s, int len)
{
	char	*tmp;

	tmp = ft_memalloc(sizeof(char) * len + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_strncpy(tmp, &asm_s->parse->line[asm_s->pos], len);
	return (tmp);
}

static int			ft_parse_reg(t_asm *asm_s, int arg_pars)
{
	int len;

	if (g_ops[asm_s->op_list->last->num].args[arg_pars] != REG \
	&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_DIR \
	&& g_ops[asm_s->op_list->last->num].args[arg_pars] != REG_DIR_IND)
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
	len = ft_count_num_len(&asm_s->parse->line[asm_s->pos]);
	asm_s->op_list->args[arg_pars].content = ft_get_content(asm_s, len);
	if (asm_s->op_list->args[arg_pars].content == NULL)
		return (EXIT_FAILURE);
	asm_s->pos += len;
	return (EXIT_SUCCESS);
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
//	else if (asm_s->parse->line[asm_s->pos] == '%')
//	{
//		if (EXIT_FAILURE == ft_parse_direct(asm_s, arg_pars))
//		{
//			//add error
//			return (EXIT_FAILURE);
//		}
//	}
//	else
//	{
//		if (EXIT_FAILURE == ft_parse_ind(asm_s, arg_pars))
//		{
//			//add error
//			return (EXIT_FAILURE);
//		}
//	}
	return (EXIT_SUCCESS);
}
