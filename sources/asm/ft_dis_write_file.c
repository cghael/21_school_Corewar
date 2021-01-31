/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_write_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:45:15 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_write_file(t_dis *dis_s)
{
	t_elem		*current;
	int			i;

	ft_dprintf(dis_s->fd_s, ".name \"%s\"\n", dis_s->name);
	ft_dprintf(dis_s->fd_s, ".comment \"%s\"\n\n", dis_s->comment);
	current = dis_s->elems;
	while (current)
	{
		ft_dprintf(dis_s->fd_s, "%s", current->op->name);
		i = 0;
		while (i < current->op->n_args)
		{
			if (current->args_types[i] == T_DIR)
				ft_dprintf(dis_s->fd_s, " %%%ld", (long)current->args[i]);
			else if (current->args_types[i] == T_IND)
				ft_dprintf(dis_s->fd_s, " %ld", (long)current->args[i]);
			else if (current->args_types[i] == T_REG)
				ft_dprintf(dis_s->fd_s, " r%ld", (long)current->args[i]);
			if (i < current->op->n_args - 1)
				ft_dprintf(dis_s->fd_s, ",");
			i++;
		}
		ft_dprintf(dis_s->fd_s, "\n");
		current = current->next;
	}
}
