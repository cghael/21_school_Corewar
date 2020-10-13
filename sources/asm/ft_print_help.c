//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

int		ft_print_help(void)
{
	ft_printf("Usage: ./asm *.s *.cor\n");
	ft_printf("    *.s   —> from assemble to bytecode\n");
	ft_printf("    *.cor —> from bytecode to assemble\n");
	return (0);
}