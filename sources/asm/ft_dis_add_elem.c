/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_add_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:33:33 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_add_elem(t_elem **list, t_elem *new)
{
	t_elem *curr;

	if (list)
	{
		if (*list)
		{
			curr = *list;
			while (curr->next)
				curr = curr->next;
			curr->next = new;
		}
		else
			*list = new;
	}
}
