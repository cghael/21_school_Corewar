//
// Created by  Anton Gorobets on 20.10.2020.
//
#include "asm.h"

static int		ft_check_name_comment_size(t_asm *asm_s)
{
	//todo check size
	if (ft_strlen(asm_s.name) > PROG_NAME_LENGTH + 1 \
			|| ft_strlen(asm_s.name) > COMMENT_LENGTH + 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int		ft_check_name_or_comment(t_asm *asm_s)
{
	int		res;
	int		pos;

	pos = 0;
	if (asm_s->quotes == NAME_START || asm_s->quotes == CMT_START)
	{
		if (EXIT_FAILURE == (res = ft_open_quotes_processing(asm_s, &pos)))
			return (res);
	}
	else
	{
		if (EXIT_FAILURE == (res = ft_start_check_name_or_comment(asm_s)))
			return (res);
	}
	if (asm_s->quotes == NAME_CMT_FOUND)
		res = ft_check_name_comment_size(asm_s);
	return (res);
}

static int		ft_check_operation(t_asm *asm_s)
{
	//miss whitespaces
	return (EXIT_SUCCESS);
}

int				ft_line_data_processing(t_asm *asm_s)
{
	int		res;

	if (asm_s->quotes != NAME_CMT_FOUND)
		res = ft_check_name_or_comment(asm_s);
	else
		res = ft_check_operation(asm_s);
	return (res);
}
