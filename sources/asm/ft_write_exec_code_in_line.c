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

static void	ft_write_code_to_exec(char *exec, t_operations *tmp)
{
	int	pos;
	int i;

	i = 0;
	pos = 0;
	exec[pos] = g_ops[tmp->num].code;
	if (g_ops[tmp->num].is_args_type == TRUE)
	{
		pos++;
		exec[pos] = tmp->args_code;
	}
	while (tmp->args[i].content && i < 3)
	{
		if (tmp->args[i].type == REG_CODE)
		{
			pos++;
			ft_strcpy(&exec[pos], tmp->args[i].content);
		}
		else if (tmp->args[i].type == DIR_CODE)
		{
			ft_memcpy(&exec[pos + 1], tmp->args[i].content, g_ops[tmp->num].t_dir_size);
			pos += g_ops[tmp->num].t_dir_size;
		}
		//todo add IND_CODE
		i++;
	}
}

static int	ft_add_op_exec_code(t_asm *asm_s, t_operations *tmp)
{
	int		len;
	char	*exec;

	len = ft_count_op_exec_len(tmp);
	exec = (char*)ft_memalloc(sizeof(*exec) * len + 1);
	ft_write_code_to_exec(exec, tmp);
	asm_s->code = ft_strjoin_n_free(asm_s->code, exec); //todo join don't work
	if (asm_s->code == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			ft_write_exec_code_in_line(t_asm *asm_s)
{
	t_operations	*tmp;

	asm_s->code = ft_memalloc(sizeof(char) * asm_s->exec_size + 1);
	if (asm_s->code == NULL)
		return (EXIT_FAILURE);
	tmp = asm_s->op_list;
	while (tmp)
	{
		if (EXIT_FAILURE == ft_add_op_exec_code(asm_s, tmp))
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
