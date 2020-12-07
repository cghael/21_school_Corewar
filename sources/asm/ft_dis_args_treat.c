/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_args_treat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:42:51 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 12:42:53 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_dis_args_treat(t_dis *dis_s, t_elem *elems)
{
	unsigned	i;

	i = 0;
	while (i < elems->op->n_args)
	{
		ft_dis_arg_treat(dis_s, elems, i);
		i++;
	}
}
