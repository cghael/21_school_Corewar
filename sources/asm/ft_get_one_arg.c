/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_one_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:23:49 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:23:51 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			ft_create_arg_content(t_asm *asm_s, int arg_pars, int size)
{
	int		num;

	asm_s->op_list->last->args[arg_pars].content = \
										ft_memalloc(sizeof(char) * size);
	if (asm_s->op_list->last->args[arg_pars].content == NULL)
		return (EXIT_FAILURE);
	num = ft_atoi(&asm_s->parse->line[asm_s->pos]);
	ft_int32_to_bytecode(asm_s->op_list->last->args[arg_pars].content, \
																0, num, size);
	return (EXIT_SUCCESS);
}

static int			ft_parse_reg(t_asm *asm_s, int arg_pars)
{
	int	len;

	if (EXIT_FAILURE == ft_check_arg_type(asm_s, T_REG, arg_pars))
		return (EXIT_FAILURE);
	if (asm_s->parse->line[asm_s->pos] < 48 \
	|| asm_s->parse->line[asm_s->pos] > 59)
	{
		asm_s->parse->err_num = INCORRECT_REG;
		return (EXIT_FAILURE);
	}
	len = ft_count_num_len(&asm_s->parse->line[asm_s->pos]);
	if (ft_atoi(&asm_s->parse->line[asm_s->pos]) < 1 || len > 2)
	{
		asm_s->parse->err_num = INCORRECT_REG;
		return (EXIT_FAILURE);
	}
	if (EXIT_FAILURE == ft_create_arg_content(asm_s, arg_pars, 1))
		return (EXIT_FAILURE);
	if (asm_s->op_list->last->args[arg_pars].content == NULL)
		return (EXIT_FAILURE);
	asm_s->pos += len;
	asm_s->op_list->last->args[arg_pars].type = REG_CODE;
	return (EXIT_SUCCESS);
}

static int			ft_parse_direct(t_asm *asm_s, int arg_pars)
{
	int		sign;

	if (EXIT_FAILURE == ft_check_arg_type(asm_s, T_DIR, arg_pars))
		return (EXIT_FAILURE);
	if (asm_s->parse->line[asm_s->pos] == LABEL_CHAR)
		return (ft_get_label_mention(asm_s, arg_pars, DIR_CODE));
	sign = asm_s->parse->line[asm_s->pos] == '-' ? -1 : 0;
	asm_s->pos += (sign) ? 1 : 0;
	if (asm_s->parse->line[asm_s->pos] < 48 \
	|| asm_s->parse->line[asm_s->pos] > 59)
	{
		asm_s->parse->err_num = INCORRECT_DIR;
		return (EXIT_FAILURE);
	}
	asm_s->pos += (sign) ? -1 : 0;
	if (EXIT_FAILURE == ft_create_arg_content(asm_s, arg_pars, \
								g_ops[asm_s->op_list->last->num].t_dir_size))
		return (EXIT_FAILURE);
	asm_s->pos += (sign) ? 1 : 0;
	asm_s->pos += ft_count_num_len(&asm_s->parse->line[asm_s->pos]);
	asm_s->op_list->last->args[arg_pars].type = DIR_CODE;
	return (EXIT_SUCCESS);
}

static int			ft_parse_indirect(t_asm *asm_s, int arg_pars)
{
	int		sign;

	if (EXIT_FAILURE == ft_check_arg_type(asm_s, T_IND, arg_pars))
		return (EXIT_FAILURE);
	if (asm_s->parse->line[asm_s->pos] == LABEL_CHAR)
		return (ft_get_label_mention(asm_s, arg_pars, IND_CODE));
	sign = asm_s->parse->line[asm_s->pos] == '-' ? -1 : 0;
	asm_s->pos += (sign) ? 1 : 0;
	if (asm_s->parse->line[asm_s->pos] < 48 \
	|| asm_s->parse->line[asm_s->pos] > 59)
	{
		asm_s->parse->err_num = INCORRECT_IND;
		return (EXIT_FAILURE);
	}
	asm_s->pos += (sign) ? -1 : 0;
	if (EXIT_FAILURE == ft_create_arg_content(asm_s, arg_pars, IND_SIZE))
		return (EXIT_FAILURE);
	asm_s->pos += (sign) ? 1 : 0;
	asm_s->pos += ft_count_num_len(&asm_s->parse->line[asm_s->pos]);
	asm_s->op_list->last->args[arg_pars].type = IND_CODE;
	return (EXIT_SUCCESS);
}

int					ft_get_one_arg(t_asm *asm_s, int arg_pars)
{
	if (asm_s->parse->line[asm_s->pos] == 'r')
	{
		if (EXIT_FAILURE == ft_parse_reg(asm_s, arg_pars))
			return (EXIT_FAILURE);
	}
	else if (asm_s->parse->line[asm_s->pos] == '%')
	{
		if (EXIT_FAILURE == ft_parse_direct(asm_s, arg_pars))
			return (EXIT_FAILURE);
	}
	else
	{
		if (EXIT_FAILURE == ft_parse_indirect(asm_s, arg_pars))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
