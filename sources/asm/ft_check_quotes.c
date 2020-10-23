//
// Created by  Anton Gorobets on 21.10.2020.
//

#include "asm.h"

int			ft_check_quotes(t_asm *asm_s, int *pos)
{
	while (asm_s->parse->line[*pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[*pos]))
			(*pos)++;
		else if (asm_s->parse->line[*pos] == '"')
		{
			*pos += 1;
			return (ft_open_quotes_processing(asm_s, pos));
		}
		else
		{
			//todo error position
			return (EXIT_FAILURE); //если нашел не whitespace и не ковычку
		}
	}
	//todo error position
	return (EXIT_FAILURE); //если до конца строки одни whitespaces
}
