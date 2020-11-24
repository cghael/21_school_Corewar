//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void	ft_asm_error_in_line(t_asm *asm_s)
{
	if (asm_s != NULL)
	{
		ft_dprintf(2, "\e[1;31mERROR IN LINE \e[1;33m[%d, %d]:\e[m%s\n\n" \
			"\e[1;34m%*cへ(ಠ╭╮ಠ)< fix it!\e[m\n\e[1;13m%s\n\n", \
			asm_s->parse->n_line, asm_s->pos + 1, \
			g_error[(int)asm_s->parse->err_num], asm_s->pos + 1, \
			'v', asm_s->parse->line);
	}
}

void	ft_asm_error(char *error_text, t_asm *asm_s)
{
	ft_dprintf(2, "ERROR ______________ %s\n", error_text);
	if (asm_s)
		ft_free_asm_struct(asm_s);
	asm_s = NULL;
}

int		ft_dis_error(char *error_text, void *data_for_free)
{
	ft_dprintf(STDERR_FILENO, error_text);
	if (data_for_free != NULL)
		free(data_for_free);
	return (EXIT_FAILURE);
}