//
// Created by leathertube on 14.10.2020.
//

#include "asm.h"

static int	ft_check_command_name(char *line, t_asm *asm_s)
{
	if (STRINGS_EQU == ft_strnequ(line, "name", 4))
		return (ft_parse_name(line + 4, asm_s));
	if (STRINGS_EQU == ft_strnequ(line, "comment", 7))
		return (ft_parse_comment(line + 7, asm_s));
	return (EXIT_FAILURE);
}

static int	ft_is_command(char *line, t_asm *asm_s)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(line[i]))
			asm_s->column++;
		if (line[i] == '#')
			return (IS_NOT_COMMAND);
		else if (line[i] == '.')
			return (ft_check_command_name(&line[++i], asm_s));
		i++;
	}
	return (IS_NOT_COMMAND);
}

int			ft_parse_file(t_asm *asm_s)
{
	char	*line;
	int		res;
	int		command;

	while ((res = ft_get_next_line(asm_s->fd, &line)) > 0)
	{
		ft_increase_line(asm_s);
		ft_printf("readed line [%s] gnl return: %d\n", line, res);
		command = ft_is_command(line, asm_s);
		if (line)
			free(line);
		if (command == EXIT_FAILURE)
		{
			ft_asm_error_in_line("Lexical error at", asm_s);
			return (PARSING_ERR);
		}
	}
	if (res < 0)
		return (PARSING_ERR);
	return (PARSING_OK);
}