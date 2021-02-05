/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_init_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:35:26 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:35:28 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_elem		*ft_dis_init_element(t_dis *dis_s)
{
	t_elem	*elem;

	if (!(elem = (t_elem *)ft_memalloc(sizeof(t_elem))))
		ft_dis_terminate(ERR_DIS_ELEM_INIT, dis_s);
	elem->op = NULL;
	elem->next = NULL;
	return (elem);
}
