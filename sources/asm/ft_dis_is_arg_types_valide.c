/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_is_arg_types_valide.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:41:10 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:41:11 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool			ft_dis_is_arg_types_valide(t_elem *elem)
{
	int32_t		i;

	i = 0;
	while (i < elem->op->n_args)
	{
		if (!(elem->args_types[i] & elem->op->args[i]))
			return (false);
		i++;
	}
	return (true);
}
