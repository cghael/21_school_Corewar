
#include "asm.h"
t_bool	ft_is_arg_types_valide(t_elem *statement)
{
	int32_t i;

	i = 0;
	while (i < statement->op->n_args)
	{
		if (!(statement->args_types[i] & statement->op->args[i]))
			return (false);
		i++;
	}
	return (true);
}
