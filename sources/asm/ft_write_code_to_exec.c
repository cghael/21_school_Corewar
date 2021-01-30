/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_code_to_exec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:53:46 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_add_arg_to_exec(char *exec, t_operations *tmp, int pos)
{
	int i;

	i = 0;
	while (i < g_ops[tmp->num].n_args && tmp->args[i].content)
	{
		if (tmp->args[i].type == REG_CODE)
			ft_memcpy(&exec[++pos], tmp->args[i].content, 1);
		else if (tmp->args[i].type == DIR_CODE)
		{
			ft_memcpy(&exec[pos + 1], tmp->args[i].content, \
												g_ops[tmp->num].t_dir_size);
			pos += g_ops[tmp->num].t_dir_size;
		}
		else
		{
			ft_memcpy(&exec[pos + 1], tmp->args[i].content, IND_SIZE);
			pos += IND_SIZE;
		}
		i++;
	}
}

void		ft_write_code_to_exec(char *exec, t_operations *tmp)
{
	int	pos;

	pos = 0;
	exec[pos] = g_ops[tmp->num].code;
	if (g_ops[tmp->num].is_args_type == TRUE)
	{
		pos++;
		exec[pos] = tmp->args_code;
	}
	ft_add_arg_to_exec(exec, tmp, pos);
}
