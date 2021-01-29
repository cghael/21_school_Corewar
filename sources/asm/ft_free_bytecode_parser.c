#include "asm.h"

static void	ft_free_statements(t_elem **list)
{
	t_elem	*current;
	t_elem	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_memdel((void **)&delete);
	}
	*list = NULL;
}

void		ft_free_bytecode_parser(t_dis **parser)
{
	ft_strdel(&((*parser)->name));
	ft_strdel(&((*parser)->comment));
	ft_memdel((void **)&((*parser)->code));
	ft_free_statements(&((*parser)->elems));
	ft_memdel((void **)parser);
}
