#include "asm.h"

void			ft_process_args(t_dis *parser, t_elem *statement)
{
	unsigned int i;

	i = 0;
	while (i < (unsigned int)(statement->op->n_args))
	{
		ft_process_arg(parser, statement, i);
		i++;
	}
}
