//
// Created by Cora Ghael on 11/16/20.
//
#include "asm.h"

int		ft_init_n_add_token(t_asm *asm_s)
{
	t_token		*tmp;
	t_token		*begin;

	begin = asm_s->tokens;
	tmp = ft_memalloc(sizeof(t_token));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	tmp->content = NULL;
	tmp->next = NULL;
	if (asm_s->tokens == NULL)
		asm_s->tokens = tmp;
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = tmp;
	}
	return (EXIT_SUCCESS);
}
