//
// Created by  Anton Gorobets on 20.10.2020.
//
#include "asm.h"

void		ft_parse_line(t_asm *asm_s)
{
	asm_s->parse->res = ft_get_next_line(asm_s->fd, &asm_s->parse->line);
//	if (ft_strchr(&asm_s->parse->line, '\n') == NULL)
//		asm_s->parse->end = TRUE;
	asm_s->parse->n_line++;
	asm_s->pos = 0;
}
