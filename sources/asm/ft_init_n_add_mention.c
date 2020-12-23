//
// Created by  Anton Gorobets on 23.12.2020.
//
#include "asm.h"

int			ft_init_n_add_mention(t_asm *asm_s, int arg_pars, t_label *label)
{
	t_mention	*tmp;
	t_mention	*begin;

	tmp = ft_memalloc(sizeof(t_mention));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	tmp->next = NULL;
	tmp->op = asm_s->op_list->last;
	tmp->arg_num = arg_pars;
	tmp->op_pos = asm_s->exec_size;
	tmp->pos = asm_s->pos;
	tmp->n_line = asm_s->parse->n_line;
	begin = label->mention;
	if (begin == NULL)
		label->mention = tmp;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = tmp;
	}
	return (EXIT_SUCCESS);
}
