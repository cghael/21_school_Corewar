#include "asm.h"

void		ft_set_arg_type(int8_t arg_code,
							int8_t index,
							t_elem *statement)
{
	statement->args_types[index - 1] = ft_get_arg_type(arg_code);
}