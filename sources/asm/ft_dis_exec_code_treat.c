/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_exec_code_treat.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:45:30 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 12:45:31 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_dis_exec_code_treat(t_dis *dis_s)
{
	while (dis_s->pos < dis_s->code_size)
	{
		ft_dis_add_elem(&(dis_s->elems), ft_dis_elems_treat(dis_s));
	}
}
