/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_n_add_label.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:29:15 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_init_n_add_label(t_asm *asm_s, const char *name, int n_line)
{
	t_label	*tmp;
	t_label	*begin;

	tmp = (t_label*)ft_memalloc(sizeof(t_label));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	tmp->next = NULL;
	tmp->mention = NULL;
	tmp->name = name;
	tmp->n_line = n_line;
	tmp->byte_pos = asm_s->exec_size;
	begin = asm_s->labels;
	if (begin == NULL)
		asm_s->labels = tmp;
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = tmp;
	}
	asm_s->labels->last = tmp;
	return (EXIT_SUCCESS);
}
