#include "asm.h"

void	ft_write_asm_file(int fd, t_dis *parser)
{
	t_elem	*current;
	unsigned int	i;

	ft_dprintf(fd, ".name \"%s\"\n", parser->name);
	ft_dprintf(fd, ".comment \"%s\"\n\n", parser->comment);
	current = parser->elems;
	while (current)
	{
		ft_dprintf(fd, "%s", current->op->name);
		i = 0;
		while (i < (unsigned int)current->op->n_args)
		{
			if (current->args_types[i] == T_DIR)
				ft_dprintf(fd, " %%%ld", (long)current->args[i]);
			else if (current->args_types[i] == T_IND)
				ft_dprintf(fd, " %ld", (long)current->args[i]);
			else if (current->args_types[i] == T_REG)
				ft_dprintf(fd, " r%ld", (long)current->args[i]);
			if (i < (unsigned int)current->op->n_args - 1)
				ft_dprintf(fd, ",");
			i++;
		}
		ft_dprintf(fd, "\n");
		current = current->next;
	}
}
