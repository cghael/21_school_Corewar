//
// Created by Cora Ghael on 11/17/20.
//
#include "asm.h"

static int		ft_init_n_add_operation_token(t_asm *asm_s, t_typo num)
{
	t_operations	*tmp;
	t_operations	*begin;

	begin = asm_s->op_list;
	tmp = ft_memalloc(sizeof(t_operations));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	tmp->num = num;
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

static int		ft_is_valid_op_name(t_asm *asm_s)
{
	int		i;

	i = 15;
	while (i >= 0)
	{
		if (ft_strncmp(g_ops[i].name, &asm_s->parse->line[asm_s->pos], \
												ft_strlen(g_ops[i].name)) == 0)
		{
			if (EXIT_FAILURE == ft_init_n_add_operation_token(asm_s, i))
				return (EXIT_FAILURE);
			asm_s->pos += ft_strlen(g_ops[i].name);
			if (asm_s->parse->line[asm_s->pos] != DIRECT_CHAR \
			&& EXIT_FAILURE == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
				return (EXIT_FAILURE);
			return (ft_check_n_write_op_args(asm_s));
		}
		i--;
	}
	return (EXIT_FAILURE);
}

int				ft_operation_processing_n_pos_update(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		if (asm_s->parse->line[asm_s->pos] == '#')
			return (EXIT_SUCCESS);
		if (EXIT_FAILURE == ft_is_valid_op_name(asm_s))
			return (EXIT_FAILURE);
	}
	//while (skip whitespaces) - done!
	//is operator and valid
		//arg type
		//arg value
		//separator?
	//count arg type code
	return (EXIT_SUCCESS);
}
