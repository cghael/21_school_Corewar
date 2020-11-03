//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void	ft_asm_error_in_line(t_asm *asm_s)
{
	int		error_type;

	if (asm_s != NULL)
	{
		error_type = asm_s->parse->err_num;
		//todo processing err_num
//		if (error_type == )
//		ft_dprintf(2, "%s [%d:%d]\n", ft_choose_error_text(error_type) \
//						asm_s->parse->err.line, asm_s->parse->err.column);
//		ft_free_asm_struct(asm_s);
	}
}

void	ft_asm_error(char *error_text, t_asm *asm_s)
{
	ft_dprintf(2, "%s\n", error_text);
	if (asm_s)
		ft_free_asm_struct(asm_s);
	asm_s = NULL;
}
