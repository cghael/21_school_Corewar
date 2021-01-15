/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_is_arg_types_valid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:32:28 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool		ft_dis_is_arg_types_valid(t_elem *elems)
{
	int32_t i;

	i = 0;
	while (i < elems->op->n_args)
	{
		if (!(elems->args_types[i] & elems->op->args[i]))
			return (false);
		i++;
	}
	return (true);
}
