/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_treat_exec_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:49:32 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:49:33 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_dis_treat_exec_code(t_dis *dis_s)
{
	t_elem	*tmp;

	while (dis_s->pos < dis_s->code_size)
	{
		tmp = ft_dis_args_treat(dis_s);
		if (tmp == NULL)
			return (EXIT_FAILURE);
		ft_dis_add_elem(&(dis_s->elems), tmp);
	}
	return (EXIT_SUCCESS);
}
