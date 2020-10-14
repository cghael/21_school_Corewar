//
// Created by  Anton Gorobets on 14.10.2020.
//
#include "asm.h"

int			ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
