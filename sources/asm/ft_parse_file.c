//
// Created by leathertube on 14.10.2020.
//

#include "asm.h"

int			ft_parse_file(t_asm *asm_s)
{
	char	*line;
	int		res;

	res = 1;
	while (res)
	{
		res = ft_get_next_line(asm_s->fd, &line);
		ft_printf("readed line [%s] gnl return: %d\n", line, res);
	}
	return (PARSING_OK);
}