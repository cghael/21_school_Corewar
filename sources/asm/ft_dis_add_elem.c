/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_add_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:48:58 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:48:59 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_dis_add_elem(t_elem **list, t_elem *new)
{
	t_elem		*cur;

	if (list)
	{
		if (*list)
		{
			cur = *list;
			while (cur->next)
				cur = cur->next;
			cur->next = new;
		}
		else
			*list = new;
	}
}
