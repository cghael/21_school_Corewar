//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void	ft_asm_error(char *error_text, t_asm *asm_struct)
{
	ft_dprintf(2, "%s\n", error_text);
	if (asm_struct)
		ft_free_asm_struct(asm_struct);
	exit(EXIT_FAILURE);
}
