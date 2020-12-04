//
// Created by leathertube on 14.10.2020.
//

#include "asm.h"

static int	ft_parsing_processing(t_asm *asm_s)
{
	ft_parse_line(asm_s);
	while (asm_s->parse->res > 0)
	{
		asm_s->parse->is_whitespace = FALSE;
		ft_printf("Read line [%s] gnl return: %d\n", asm_s->parse->line, asm_s->parse->res);//todo del
		if (EXIT_FAILURE == ft_line_data_processing(asm_s))
		{
			ft_printf("Error in ft_parsing_processing()\n");//todo del
			ft_asm_error_in_line(asm_s);
			return (PARSING_ERR);
		}
		if (asm_s->parse->line)
		{
			free(asm_s->parse->line);
			asm_s->parse->line = NULL;
		}
		ft_parse_line(asm_s);
	}
	if (asm_s->parse->res < 0)
		return (PARSING_ERR);
	return (PARSING_OK);
}

int			ft_parse_file(t_asm *asm_s)
{
	if (EXIT_FAILURE == ft_check_end_newline(asm_s))
		return (PARSING_ERR);
	if (PARSING_ERR == ft_parsing_processing(asm_s))
		return (PARSING_ERR);

	//check end newline
	if (asm_s->parse->res == 0 \
	&& asm_s->parse->endline == TRUE \
	&& asm_s->parse->is_whitespace == FALSE)
	{
		ft_asm_error_in_line(asm_s); //todo forget newline
		ft_printf("Error in ft_parse_file()\n");//todo del
		return (PARSING_ERR);
	}
	if (EXIT_FAILURE == ft_write_exec_code_in_line(asm_s))
		return (PARSING_ERR);
	return (PARSING_OK);
}