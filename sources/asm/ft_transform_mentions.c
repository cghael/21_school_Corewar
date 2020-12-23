//
// Created by  Anton Gorobets on 23.12.2020.
//
#include "asm.h"

static char		*ft_create_content(t_asm *asm_s, int size)
{
	char	*content;
	int		num;

	content = ft_memalloc(sizeof(char) * size);
	if (content == NULL)
		return (NULL);
	num = asm_s->labels->byte_pos - asm_s->labels->mention->op_pos;
	ft_int32_to_bytecode(content, 0, num, size);
	return (content);
}

static int		ft_add_arg_content(t_asm *asm_s)
{
	int		arg_num;
	int		size;

	arg_num = asm_s->labels->mention->arg_num;
	if (asm_s->labels->mention->op->args[arg_num].type == DIR_CODE)
		size = g_ops[asm_s->labels->mention->op->num].t_dir_size;
	else if (asm_s->labels->mention->op->args[arg_num].type == IND_CODE)
		size = IND_SIZE;
	else
		return (EXIT_FAILURE);
	asm_s->labels->mention->op->args[arg_num].content = \
												ft_create_content(asm_s, size);
	if (asm_s->labels->mention->op->args[arg_num].content == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				ft_transform_mentions(t_asm *asm_s)
{
	while (asm_s->labels)
	{
		while (asm_s->labels->mention)
		{
			if (asm_s->labels->n_line == 0)
				return (EXIT_FAILURE);
			if (EXIT_FAILURE == ft_add_arg_content(asm_s))
				return (EXIT_FAILURE);
			asm_s->labels->mention = asm_s->labels->mention->next;
		}
		asm_s->labels = asm_s->labels->next;
	}
	return (EXIT_SUCCESS);
}
