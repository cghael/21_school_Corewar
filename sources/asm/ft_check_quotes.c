//
// Created by  Anton Gorobets on 21.10.2020.
//

#include "asm.h"

static int	ft_copy_content_to_struct(t_asm *asm_s, int *i, int flag)
{
	int		len;
	int		res;

	len = *i + 1;

	while (asm_s->parse->line[len])
	{
		if (asm_s->parse->line[len] == '"')
		{
			asm_s->quotes++; //START turn into END
			break ;
		}
		len++;
	}
	//todo save line
	res = ft_copy_line();
	//todo check line is empty or #
	return (res);
}

static int	ft_open_quotes_processing(t_asm *asm_s, int *i, int flag)
{
	int res;

	asm_s->quotes = flag;
//	if (flag == NAME_START)
//		asm_s->quotes = NAME_START;
//	else
//		asm_s->quotes = CMT_START;
	res = ft_copy_content_to_struct(asm_s, i, flag);
	return (res);
}

int			ft_check_quotes(t_asm *asm_s, int *i, int flag)
{
	while (asm_s->parse->line[*i])
	{
		if (ft_is_whitespace(asm_s->parse->line[*i]))
			(*i)++;
		else if (asm_s->parse->line[*i] == '"')
			return (ft_open_quotes_processing(asm_s, i, flag));
		else
		{
			//todo error position
			return (EXIT_FAILURE); //если нашел не whitespace и не ковычку
		}
	}
	//todo error position
	return (EXIT_FAILURE); //если до конца строки одни whitespaces
}
