//
// Created by  Anton Gorobets on 21.12.2020.
//
#include "asm.h"

t_label			*ft_search_label_exist(t_asm *asm_s, char *name)
{
	t_label	*tmp;

	tmp = asm_s->labels;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
