/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_write_op_args.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:03:30 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:03:34 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_move_pos_to_separator(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		else if (asm_s->parse->line[asm_s->pos] == SEPARATOR_CHAR)
		{
			asm_s->pos++;
			return (EXIT_SUCCESS);
		}
		else
		{
			asm_s->parse->err_num = NO_SEPARATOR;
			return (EXIT_FAILURE);
		}
	}
	asm_s->parse->err_num = FEW_ARGS;
	return (EXIT_FAILURE);
}

static int	ft_parse_arg(t_asm *asm_s, int arg_pars)
{
	if (EXIT_FAILURE == ft_get_one_arg(asm_s, arg_pars))
		return (EXIT_FAILURE);
	if ((arg_pars + 1) < g_ops[asm_s->op_list->last->num].n_args)
	{
		if (EXIT_FAILURE == ft_move_pos_to_separator(asm_s))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			ft_check_n_write_op_args(t_asm *asm_s)
{
	int arg_pars;

	arg_pars = 0;
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		else if (asm_s->parse->line[asm_s->pos] == COMMENT_CHAR \
					|| asm_s->parse->line[asm_s->pos] == ALT_COMMENT_CHAR)
			break ;
		else if (arg_pars < g_ops[asm_s->op_list->last->num].n_args)
		{
			if (EXIT_FAILURE == ft_parse_arg(asm_s, arg_pars))
				return (EXIT_FAILURE);
			arg_pars++;
		}
		else
		{
			asm_s->parse->err_num = LEXICAL_ERROR;
			return (EXIT_FAILURE);
		}
	}
	ft_write_arg_type_code(asm_s);
	ft_count_exec_code_size(asm_s);
	return (EXIT_SUCCESS);
}
