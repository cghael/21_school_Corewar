//
// Created by  Anton Gorobets on 02.11.2020.
//
#include "asm.h"

static int		ft_label_processing_n_pos_update(t_asm *asm_s)
{
	char	*colon;
	int		label;
	int		pos;

	label = FALSE;
	pos = asm_s->pos;
	while ((colon = ft_strchr(&asm_s->parse->line[pos], LABEL_CHAR)) != NULL)
	{
		if (EXIT_SUCCESS == ft_is_label_in_line(asm_s, colon) && label == FALSE)
		{
			ft_label_saving_n_pos_update(asm_s);
			label = TRUE;
			pos = asm_s->pos;
		}
		else if (EXIT_FAILURE == ft_is_mention(asm_s, colon, &pos))
		{
			//todo ERROR MANAGE
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int				ft_check_operation(t_asm *asm_s)
{
	if (EXIT_SUCCESS == ft_line_of_whitespaces_or_comment(asm_s))
	{
		asm_s->parse->is_whitespace = TRUE;
		return (EXIT_SUCCESS);
	}
	while (asm_s->parse->line[asm_s->pos])
	{
		if (asm_s->parse->line[asm_s->pos] == COMMENT_CHAR) //todo add alt comment
			return (EXIT_SUCCESS);
		else if (EXIT_FAILURE == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
		{
			//is ':' in line and is it label or mention
			if (EXIT_FAILURE == ft_label_processing_n_pos_update(asm_s))
				return (EXIT_FAILURE);
			//is it operation and is it single
			if (EXIT_FAILURE == ft_operation_processing_n_pos_update(asm_s))
				return (EXIT_FAILURE);
		}
		else
			asm_s->pos++;
	}
	return (EXIT_SUCCESS);
}
