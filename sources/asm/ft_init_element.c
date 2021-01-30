/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:30:26 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/30 16:30:28 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_elem	*ft_init_element(void)
{
	t_elem *elem;

	if (!(elem = (t_elem *)ft_memalloc(sizeof(t_elem))))
		ft_terminate(ERR_DIS_ELEM_INIT);
	elem->op = NULL;
	elem->next = NULL;
	return (elem);
}
