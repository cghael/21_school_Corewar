/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg_types_valide.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:30:48 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	ft_is_arg_types_valide(t_elem *statement)
{
	int32_t i;

	i = 0;
	while (i < statement->op->n_args)
	{
		if (!(statement->args_types[i] & statement->op->args[i]))
			return (false);
		i++;
	}
	return (true);
}
