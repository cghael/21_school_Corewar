//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void	ft_free_asm_struct(t_asm *asm_struct)
{
	ft_dprintf(2, "free asm_struct\n");
	if (asm_struct) // todo free all data
		free(asm_struct);
}
