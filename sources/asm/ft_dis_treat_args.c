/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_treat_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:20:16 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:20:17 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					ft_dis_treat_args(t_dis *dis_s, t_elem *elem)
{
	unsigned int	i;

	i = 0;
	while (i < (unsigned int)(elem->op->n_args))
	{
		if (EXIT_FAILURE == ft_dis_treat_arg(dis_s, elem, i))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
