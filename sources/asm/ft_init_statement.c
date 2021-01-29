#include "asm.h"

t_elem	*ft_init_statement(void)
{
	t_elem *statement;

	if (!(statement = (t_elem *)ft_memalloc(sizeof(t_elem))))
		ft_terminate(ERR_STATEMENT_INIT);
	statement->op = NULL;
	statement->next = NULL;
	return (statement);
}
