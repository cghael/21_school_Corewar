//
// Created by Karina Semele on 1/27/21.
//


#include "asm.h"

void	ft_validate_name(t_dis *parser)
{
	size_t i;

	i = ft_strlen(parser->name);
	while (i < PROG_NAME_LENGTH)
	{
		if (parser->name[i])
		{
			ft_name_warning(i);
			return ;
		}
		i++;
	}
}
