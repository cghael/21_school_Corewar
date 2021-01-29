#include "asm.h"

void	ft_add_statement(t_elem **list, t_elem *new)
{
	t_elem *current;

	if (list)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*list = new;
	}
}
