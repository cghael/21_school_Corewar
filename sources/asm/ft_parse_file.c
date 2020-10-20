//
// Created by leathertube on 14.10.2020.
//

#include "asm.h"

//static int	ft_check_command_name(char *line, t_asm *asm_s)
//{
//	if (STRINGS_EQU == ft_strnequ(line, "name", 4))
//	{
//		if (asm_s->name)
//			return (ERR_DOUBLE_NAME);
//		return (ft_parse_name(line + 4, asm_s));
//	}
//	if (STRINGS_EQU == ft_strnequ(line, "comment", 7))
//	{
//		if (asm_s->comment)
//			return (ERR_DOUBLE_COMMENT);
//		return (ft_parse_comment(line + 7, asm_s));
//	}
//	return (ERR_UNKNOWN_CMD);
//}
//
//static int	ft_is_command(char *line, t_asm *asm_s)
//{
//	int i;
//
//	i = 0;
//	while (line[i])
//	{
//		if (EXIT_SUCCESS == ft_is_whitespace(line[i]))
//			asm_s->column++;
//		if (line[i] == '#')
//			return (0);
//		else if (line[i] == '.')
//			return (ft_check_command_name(&line[++i], asm_s));
//		i++;
//	}
//	return (0);
//}

int			ft_parse_file(t_asm *asm_s)
{
	int		processing_res;

	ft_parse_line(asm_s);
	while (asm_s->parse->res > 0)
	{
		ft_printf("Read line [%s] gnl return: %d\n", asm_s->parse->line, asm_s->parse->res);//todo del
		processing_res = ft_line_data_processing(asm_s);
		if (processing_res == EXIT_FAILURE)
		{
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