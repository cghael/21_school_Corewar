/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_get_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:40:35 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t		ft_dis_get_size(t_elem *elems, unsigned i)
{
	if (elems->args[i] == T_REG)
		return (1);
	else if (elems->args[i] == T_IND)
		return (IND_SIZE);
	else
		return (elems->op->t_dir_size);
}
