//
// Created by  Anton Gorobets on 02.11.2020.
//
#include "asm.h"

int		ft_check_operation(t_asm *asm_s)
{
	char *colon;

	if (EXIT_SUCCESS == ft_line_of_whitespaces_or_comment(asm_s))
	{
		asm_s->parse->is_whitespace = TRUE;
		return (EXIT_SUCCESS);
	}
	while (asm_s->parse->line[asm_s->pos])
	{
		//is ':' in line and is it label
		if ((colon = ft_strchr(&asm_s->parse->line[asm_s->pos], LABEL_CHAR)))
		{
			//is it label and is it single //todo single
			if (EXIT_SUCCESS == ft_is_label_in_line(asm_s, colon))
				ft_label_processing_n_pos_update(asm_s);
			//is it mention
			else if (EXIT_FAILURE == ft_is_mention(asm_s, colon))
				return (EXIT_FAILURE);
		}
		//is it operation and is it single
		else if (EXIT_FAILURE == ft_operation_processing_n_pos_update(asm_s))
			return (EXIT_FAILURE);
	}
	//is operation
	return (EXIT_SUCCESS);
}
