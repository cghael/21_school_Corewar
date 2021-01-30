/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:54:45 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_process_exec_code(t_dis *dis_s)
{
	while (dis_s->pos < dis_s->code_size)
		ft_add_statement(&(dis_s->elems), ft_args_treat(dis_s));
}
