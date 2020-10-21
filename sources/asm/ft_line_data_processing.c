//
// Created by  Anton Gorobets on 20.10.2020.
//
#include "asm.h"

static int		ft_check_name_or_comment(t_asm *asm_s)
{
	int		res;

	if (asm_s->quotes == NAME_START || asm_s->quotes == CMT_START)
//		res = ft_continue_checking(asm_s);
		res = 1;//todo del
	else
		res = ft_start_check_name_or_comment(asm_s);//miss whitespaces
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
