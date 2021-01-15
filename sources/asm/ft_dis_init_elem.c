/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_init_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:43:40 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_elem		*ft_dis_init_elem(void)
{
	t_elem	*elems;

	if (!(elems = (t_elem *)ft_memalloc(sizeof(t_elem))))
		ft_dis_error(ERR_DIS_STATEMENT, NULL);
	elems->op = NULL;
	elems->next = NULL;
	return (elems);
}
