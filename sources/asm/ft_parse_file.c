//
// Created by leathertube on 14.10.2020.
//

#include "asm.h"

int			ft_parse_file(t_asm *asm_s)
{
	ft_count_lines(asm_s);
	ft_parse_line(asm_s);
	while (asm_s->parse->res > 0)
	{
		ft_printf("Read line [%s] gnl return: %d\n", asm_s->parse->line, asm_s->parse->res);//todo del
		if (EXIT_FAILURE == ft_line_data_processing(asm_s))
		{
			ft_asm_error_in_line(asm_s);
			ft_printf("Error ft_asm_error_in_line() 16\n");//todo del
			return (PARSING_ERR);
		}
		if (asm_s->parse->line)
		{
			free(asm_s->parse->line);
			asm_s->parse->line = NULL;
		}
		ft_parse_line(asm_s);
	}
	if (asm_s->parse->res == 0) //&& asm_s->parse->free_line == FALSE)
	{
		ft_asm_error_in_line(asm_s); //todo forget newline
		ft_printf("Error ft_asm_error_in_line() 29\n");//todo del
		return (PARSING_ERR);
	}
	if (asm_s->parse->res < 0)
		return (PARSING_ERR);
	return (PARSING_OK);
}