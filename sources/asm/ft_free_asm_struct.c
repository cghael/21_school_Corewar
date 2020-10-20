//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void	ft_free_asm_struct(t_asm *asm_struct)
{
	ft_dprintf(2, "free asm_struct\n");
	if (asm_struct) // todo free all data
	{
		if (asm_struct->parse)
		{
			if (asm_struct->parse->line)
			{
				free(asm_struct->parse->line);
				asm_struct->parse->line = NULL;
			}
			free(asm_struct->parse);
			asm_struct->parse = NULL;
		}
		if (asm_struct->name)
			free(asm_struct->name);
		if (asm_struct->comment)
			free(asm_struct->comment);
		if (asm_struct->code)
			free(asm_struct->code);
	}
	free(asm_struct);
}
