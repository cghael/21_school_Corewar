//
// Created by  Anton Gorobets on 23.10.2020.
//
#include "asm.h"

static void	ft_update_quotes_status(t_asm *asm_s, int is_quotes)
{
		if (asm_s->quotes == NAME_START && asm_s->comment \
		|| asm_s->quotes == CMT_START && asm_s->name)
			asm_s->quotes = NAME_CMT_FOUND;
		else
			asm_s->quotes++;
}

static int	ft_copy_len(t_asm *asm_s, int start, int len, int is_quotes)
{
	char	*str;

	if (is_quotes == FALSE)
		len += 1;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (EXIT_FAILURE);
	str = ft_strncpy(str, asm_s->parse->line + start, len);
	if (is_quotes == FALSE)
		str[len - 1] = '\n';
	str[len] = '\0';
	if (asm_s->quotes == NAME_START)
		asm_s->name = ft_strjoin_n_free(asm_s->name, str);
	else if (asm_s->quotes == CMT_START)
		asm_s->comment = ft_strjoin_n_free(asm_s->comment, str);
	else
	{
		//todo error
		return (EXIT_FAILURE);
	}
	if (is_quotes == TRUE)
		ft_update_quotes_status(asm_s, is_quotes);
	return (EXIT_SUCCESS);
}

int			ft_open_quotes_processing(t_asm *asm_s, int *pos)
{
	int		start;
	int		len;
	int		res;

	len = 0;
	start = *pos;
	while (asm_s->parse->line[*pos])
	{
		if (asm_s->parse->line[*pos] == '"')
		{
			if (EXIT_FAILURE == (res = ft_copy_len(asm_s, start, len, TRUE)))
				return (res);
			if (EXIT_FAILURE == ft_line_of_whitespaces_or_comment(asm_s, *pos + 1))
			{
				//todo add error
				return (EXIT_FAILURE);
			}
			return (res);
		}
		len++;
		(*pos)++;
	}
	res = ft_copy_len(asm_s, start, len, FALSE);
	return (res);
}
