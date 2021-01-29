//
// Created by Karina Semele on 1/27/21.
//

#include "asm.h"

void	ft_validate_comment(t_dis *parser)
{
	size_t i;

	i = ft_strlen(parser->comment);
	while (i < COMMENT_LENGTH)
	{
		if (parser->comment[i])
		{
			ft_comment_warning(i);
			return ;
		}
		i++;
	}
}
