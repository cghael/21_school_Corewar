/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_free_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:23:49 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 18:23:53 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_free_elems(t_elem **elems)
{
	t_elem	*tmp;

	if (!elems)
		return (EXIT_FAILURE);
	while (*elems)
	{
		tmp = (*elems)->next;
		free(*elems);
		*elems = tmp;
	}
	return (EXIT_SUCCESS);
}

int		ft_dis_free_struct(t_dis *dis_s)
{
	if (dis_s->name)
		free(dis_s->name);
	if (dis_s->comment)
		free(dis_s->comment);
	if (dis_s->file_s)
		free(dis_s->file_s);
	if (dis_s->elems)
		ft_dis_free_elems(&dis_s->elems);
	if (dis_s->code)
		free(dis_s->code);
	return (EXIT_SUCCESS);
}
