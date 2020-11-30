//
// Created by Cora Ghael on 11/25/20.
//
#include "asm.h"

int			ft_count_num_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] < 58 && str[i] > 47)
	{
		i++;
	}
	return (i);
}
