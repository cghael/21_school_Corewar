//
// Created by Cora Ghael on 12/4/20.
//

#include "asm.h"

static int	ft_count_op_exec_len(t_operations *tmp)
{
	int len;
	int n;
	int i;

	i = 0;
	len = 1;
	if (tmp->args_code)
		len++;
	n = g_ops[tmp->num].n_args;
	while (i < n)
	{
		if (tmp->args[i].type == REG_CODE)
			len++;
		else if (tmp->args[i].type == DIR_CODE)
			len += g_ops[tmp->num].t_dir_size;
		else if (tmp->args[i].type == IND_CODE)
			len += 2;
		i++;
	}
	return (len);
}

static char	*ft_join_mem(t_asm *asm_s, char *exec, int len)
{
	char	*code;

	code = ft_memalloc(sizeof(char) * asm_s->exec_size + len + 1);
	if (code == NULL)
		return (NULL);
	ft_memcpy(code, asm_s->code, asm_s->exec_size);
	ft_memcpy(&code[asm_s->exec_size], exec, len);
	asm_s->exec_size += len;
	free(asm_s->code);

	return (code);
}

static int	ft_add_op_exec_code(t_asm *asm_s, t_operations *tmp)
{
	int		len;
	char	*exec;

	len = ft_count_op_exec_len(tmp);
	exec = (char*)ft_memalloc(sizeof(*exec) * len + 1);
	ft_write_code_to_exec(exec, tmp);
	asm_s->code = ft_join_mem(asm_s, exec, len);
	if (asm_s->code == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			ft_write_exec_code_in_line(t_asm *asm_s)
{
	t_operations	*tmp;

	asm_s->exec_size = 0; //todo check
	tmp = asm_s->op_list;
	while (tmp)
	{
		if (EXIT_FAILURE == ft_add_op_exec_code(asm_s, tmp))
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
