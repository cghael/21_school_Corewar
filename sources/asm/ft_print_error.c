//
// Created by leathertube on 16.10.2020.
//

#include "asm.h"

void	ft_print_error(char *error, char *func, int line)
{
	ft_dprintf(2, "line %d:\n\t%s in %s()\n", line, error, func);
}