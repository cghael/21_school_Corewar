//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void	ft_asm_error_in_line(char *error_text, t_asm *asm_s)
{
	if (asm_s != NULL)
	{
		ft_dprintf(2, "%s [%d:%d]\n", error_text, asm_s->line, asm_s->column);
		ft_free_asm_struct(asm_s);
	}
	asm_s = NULL;
}

void	ft_asm_error(char *error_text, t_asm *asm_s)
{
	ft_dprintf(2, "%s\n", error_text);
	if (asm_s)
		ft_free_asm_struct(asm_s);
	asm_s = NULL;
}
