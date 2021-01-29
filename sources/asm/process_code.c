#include "asm.h"

void				ft_process_exec_code(t_dis *parser)
{
	while (parser->pos < parser->code_size)
		ft_add_statement(&(parser->elems), ft_process_statement(parser));
}
