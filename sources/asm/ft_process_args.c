/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:45:37 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:45:38 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_process_args(t_dis *parser, t_elem *statement)
{
	unsigned int i;

	i = 0;
	while (i < (unsigned int)(statement->op->n_args))
	{
		ft_process_arg(parser, statement, i);
		i++;
	}
}
