//
// Created by Cora Ghael on 11/25/20.
//
#include "asm.h"

static char			*ft_get_content(t_asm *asm_s, int len, int sign)
{
	char	*tmp;
	char	*tmp_sign;
	int		malloc_len;

	malloc_len = (sign == 0) ? len + 1 : len + 2;
	tmp = ft_memalloc(sizeof(char) * malloc_len);
	if (tmp == NULL)
		return (NULL);
	if (sign)
	{
		tmp_sign = tmp;
		tmp[0] = '-';
		ft_strncpy(tmp + 1, &asm_s->parse->line[asm_s->pos], len);
		return (tmp_sign);
	}
	else
		tmp = ft_strncpy(tmp, &asm_s->parse->line[asm_s->pos], len);
	return (tmp);
}

static int			ft_parse_reg(t_asm *asm_s, int arg_pars)
{
	int len;

	if (EXIT_FAILURE == ft_check_arg_type(asm_s, T_REG, arg_pars))
		return (EXIT_FAILURE);
	if (asm_s->parse->line[asm_s->pos] < 49 \
	|| asm_s->parse->line[asm_s->pos] > 59)
	{
		asm_s->parse->err_num = INCORRECT_REG;
		return (EXIT_FAILURE);
	}
	len = ft_count_num_len(&asm_s->parse->line[asm_s->pos]);
	asm_s->op_list->args[arg_pars].content = ft_get_content(asm_s, len, 0);
	if (asm_s->op_list->args[arg_pars].content == NULL)
		return (EXIT_FAILURE);
	asm_s->pos += len;
	return (EXIT_SUCCESS);
}

static int			ft_parse_direct(t_asm *asm_s, int arg_pars)
{
	int		sign;
	int		len;

	if (EXIT_FAILURE == ft_check_arg_type(asm_s, T_DIR, arg_pars))
		return (EXIT_FAILURE);
	if (asm_s->parse->line[asm_s->pos] == LABEL_CHAR)
		return (ft_get_label_mention(asm_s, arg_pars));
	sign = asm_s->parse->line[asm_s->pos] == '-' ? -1 : 0;
	if (sign)
		asm_s->pos++;
	if (asm_s->parse->line[asm_s->pos] < 49 \
	|| asm_s->parse->line[asm_s->pos] > 59)
	{
		asm_s->parse->err_num = INCORRECT_DIR;
		return (EXIT_FAILURE);
	}
	len = ft_count_num_len(&asm_s->parse->line[asm_s->pos]);
	asm_s->op_list->args[arg_pars].content = ft_get_content(asm_s, len, sign);
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
			return (EXIT_FAILURE);
	}
	else if (asm_s->parse->line[asm_s->pos] == '%')
	{
		if (EXIT_FAILURE == ft_parse_direct(asm_s, arg_pars))
			return (EXIT_FAILURE);
	}
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
