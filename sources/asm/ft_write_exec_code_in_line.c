//
// Created by Cora Ghael on 12/4/20.
//

#include "asm.h"

int			ft_write_exec_code_in_line(t_asm *asm_s)
{
	t_operations	*tmp;

	asm_s->code = ft_memalloc(sizeof(char) * asm_s->exec_size + 1);
	if (asm_s->code == NULL)
		return (EXIT_FAILURE);
	tmp = asm_s->op_list;
	while (tmp)
	{
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
