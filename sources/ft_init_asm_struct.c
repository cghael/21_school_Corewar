//
// Created by leathertube on 12.10.2020.
//
#include "asm.h"

t_asm		*ft_init_asm_struct(void)
{
	t_asm	*asm_struct;

	asm_struct = ft_memalloc(sizeof(t_asm));
	if (asm_struct == NULL)
	{
		ft_dprintf(2, MEMALLOC_ERR);
		ft_dprintf(2, " in ft_init asm_struct\n");
	}
	return (asm_struct);
}
