/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bytecode_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:21:45 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:21:47 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_free_statements(t_elem **list)
{
	t_elem	*current;
	t_elem	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_memdel((void **)&delete);
	}
	*list = NULL;
}

void		ft_free_bytecode_parser(t_dis **parser) //todo is it ok???
{
	ft_strdel(&((*parser)->name));
	ft_strdel(&((*parser)->comment));
	ft_memdel((void **)&((*parser)->code));
	ft_free_statements(&((*parser)->elems));
	ft_memdel((void **)parser);
}
