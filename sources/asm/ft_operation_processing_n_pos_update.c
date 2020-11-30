//
// Created by Cora Ghael on 11/17/20.
//
#include "asm.h"

static t_args	*ft_add_args_array(t_typo num)
{
	t_args	*tmp;
	int		i;

	tmp = ft_memalloc(sizeof(t_args) * g_ops[num].n_args);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < g_ops[num].n_args)
	{
		tmp[i].content = NULL;
		tmp[i].is_label = FALSE;
		i++;
	}
	return (tmp);
}

static int		ft_init_n_add_operation_token(t_asm *asm_s, t_typo num)
{
	t_operations	*tmp;
	t_operations	*begin;

	begin = asm_s->op_list;
	tmp = ft_memalloc(sizeof(t_operations));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	tmp->num = num;
	tmp->args = ft_add_args_array(num);
	if (tmp->args == NULL)
		return (EXIT_FAILURE);
	tmp->next = NULL;
	if (begin == NULL)
		asm_s->op_list = tmp;
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = tmp;
	}
	asm_s->op_list->last = tmp;
	return (EXIT_SUCCESS);
}

static int		ft_get_op_len(char *str)
{
	int len;

	len = 0;
	while (str[len] && EXIT_FAILURE == ft_is_whitespace(str[len]) \
	&& str[len] != DIRECT_CHAR)
		len++;
	return (len);
}

static int		ft_is_valid_op_name(t_asm *asm_s)
{
	int		i;
	int		len;

	i = 0;
	len = ft_get_op_len(&asm_s->parse->line[asm_s->pos]);
	while (i < COMMANDS_NUM)
	{
		if (ft_strncmp(g_ops[i].name, &asm_s->parse->line[asm_s->pos], len) == 0)
		{
			if (EXIT_FAILURE == ft_init_n_add_operation_token(asm_s, i))
				return (EXIT_FAILURE);
			asm_s->pos += ft_strlen(g_ops[i].name);
			if (asm_s->parse->line[asm_s->pos] != DIRECT_CHAR \
			&& EXIT_FAILURE == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
				return (EXIT_FAILURE);
			return (ft_check_n_write_op_args(asm_s));
		}
		i++;
	}
	asm_s->parse->err_num = UNKNOWN_OPERATOR;
	return (EXIT_FAILURE);
}

int				ft_operation_processing_n_pos_update(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		if (asm_s->parse->line[asm_s->pos] == COMMENT_CHAR \
		|| asm_s->parse->line[asm_s->pos] == ALT_COMMENT_CHAR)
			break ;
		if (EXIT_FAILURE == ft_is_valid_op_name(asm_s))
			return (EXIT_FAILURE);
	}
	ft_write_arg_type_code(asm_s);
	return (EXIT_SUCCESS);
}
