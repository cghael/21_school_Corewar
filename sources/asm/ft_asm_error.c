//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void	ft_asm_error_in_line(t_asm *asm_s)
{
	int		error_type;

	if (asm_s != NULL)
	{
		ft_dprintf(2, "ERROR_IN_LINE \e[1;33m[%d, %d]:\e[m\n"
			"\e[1;34m%*cへ(ಠ╭╮ಠ)< fix it!\e[m\n\e[1;13m%s\n",
			asm_s->parse->n_line, asm_s->pos, asm_s->pos + 1,
			'V', asm_s->parse->line);
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
	ft_dprintf(2, "ERROR ______________ %s\n", error_text);
	if (asm_s)
		ft_free_asm_struct(asm_s);
	asm_s = NULL;
}
