//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

static void		ft_free_labels(t_asm *asm_struct)
{
	t_label		*tmp;
	t_mention	*tmp_m;

	tmp = asm_struct->labels;
	while (tmp)
	{
		asm_struct->labels = asm_struct->labels->next;
		tmp_m = tmp->mention;
		while (tmp_m)
		{
			tmp->mention = tmp->mention->next;
			free(tmp_m);
			tmp_m = NULL;
			tmp_m = tmp->mention;
		}
		free(tmp);
		tmp = NULL;
		tmp = asm_struct->labels;
	}
}

static void		ft_free_ops(t_asm *asm_struct)
{
	t_op	*tmp;

	tmp = asm_struct->ops;
	while (tmp)
	{
		asm_struct->ops = asm_struct->ops->next;
		free((void*)tmp->name);
		free(tmp);
		tmp = NULL;
		tmp = asm_struct->ops;
	}
}

void	ft_free_asm_struct(t_asm *asm_struct)
{
	ft_dprintf(2, "free asm_struct\n");
	if (asm_struct) // todo free all data
	{
		if (asm_struct->parse)
		{
			if (asm_struct->parse->line)
			{
				free(asm_struct->parse->line);
				asm_struct->parse->line = NULL;
			}
			free(asm_struct->parse);
			asm_struct->parse = NULL;
		}
		if (asm_struct->name)
			free(asm_struct->name);
		if (asm_struct->comment)
			free(asm_struct->comment);
		if (asm_struct->code)
			free(asm_struct->code);
		ft_free_labels(asm_struct);
		ft_free_ops(asm_struct);
	}
	free(asm_struct);
}
