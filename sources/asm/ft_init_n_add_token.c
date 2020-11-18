//
// Created by Cora Ghael on 11/16/20.
//
#include "asm.h"

int		ft_init_n_add_token(t_asm *asm_s, t_typo typo, char *content)
{
	t_token		*tmp;
	t_token		*begin;

	begin = asm_s->tokens;
	tmp = ft_memalloc(sizeof(t_token));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	tmp->typo = typo;
	tmp->content = content;
	tmp->next = NULL;
	tmp->pos = asm_s->pos - (int)ft_strlen(content) - 1; //todo if reg or arg???
	tmp->n_line = asm_s->parse->n_line;
	if (asm_s->tokens == NULL)
		asm_s->tokens = tmp;
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = tmp;
	}
	asm_s->tokens->last = tmp;
	return (EXIT_SUCCESS);
}
