//
// Created by Cora Ghael on 11/23/20.
//
#include "asm.h"

int			ft_is_label_char(char ch)
{
	int		i;
	char	str[] = LABEL_CHARS;

	i = 0;
	while (str[i])
	{
		if (ch == str[i])
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}