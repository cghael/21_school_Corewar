//
// Created by Karina Semele on 1/27/21.
//

//#include "asm_op.h"
#include "asm.h"

size_t		ft_get_size(t_elem *statement, unsigned i)
{
	if (statement->args_types[i] == T_REG)
		return (1);
	else if (statement->args_types[i] == T_IND)
		return (IND_SIZE);
	else
		return (statement->op->t_dir_size);
}
