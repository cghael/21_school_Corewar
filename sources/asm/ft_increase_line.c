//
// Created by  Anton Gorobets on 14.10.2020.
//
#include "asm.h"

void		ft_increase_line(t_asm *asm_s)
{
	asm_s->line++;
	asm_s->column = 1;
}
