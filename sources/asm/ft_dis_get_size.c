/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_get_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:10:52 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:10:53 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t		ft_dis_get_size(t_elem *elem, unsigned int i)
{
	if (elem->args_types[i] == T_REG)
		return (1);
	else if (elem->args_types[i] == T_IND)
		return (IND_SIZE);
	else
		return (elem->op->t_dir_size);
}
