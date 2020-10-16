//
// Created by leathertube on 14.10.2020.
//

#include "asm.h"

static int	ft_check_command_name(char *line, t_asm *asm_s)
{
	if (STRINGS_EQU == ft_strnequ(line, "name", 4))
	{
		if (asm_s->name)
			return (ERR_DOUBLE_NAME);
		return (ft_parse_name(line + 4, asm_s));
	}
	if (STRINGS_EQU == ft_strnequ(line, "comment", 7))
	{
		if (asm_s->comment)
			return (ERR_DOUBLE_COMMENT);
		return (ft_parse_comment(line + 7, asm_s));
	}
	return (ERR_UNKNOWN_CMD);
}

/*
** Return	0				there is comment in line or whitespaces
**			res				result ft_check_command_name()
*/

static int	ft_is_command(char *line, t_asm *asm_s)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(line[i]))
			asm_s->column++;
		if (line[i] == '#')
			return (0);
		else if (line[i] == '.')
			return (ft_check_command_name(&line[++i], asm_s));
		i++;
	}
	return (0);
}

/*
** Return	PARSING_OK
**			PARSING_ERR
*/

int			ft_parse_file(t_asm *asm_s)
{
	char	*line;
	int		res;
	int		command;

	while ((res = ft_get_next_line(asm_s->fd, &line)) > 0)
	{
		ft_increase_line(asm_s);
		ft_printf("readed line [%s] gnl return: %d\n", line, res);//todo del
		command = ft_is_command(line, asm_s);
		if (line)
			free(line);
		if (command < 0)
		{
			ft_asm_error_in_line("Lexical error at", asm_s);//todo add error code
			return (PARSING_ERR);
		}
	}
	if (res < 0)
		return (PARSING_ERR);
	return (PARSING_OK);
}