/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_asm_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:27:41 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:27:43 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm		*ft_init_asm_struct(void)
{
	t_asm	*asm_struct;

	asm_struct = ft_memalloc(sizeof(t_asm));
	if (asm_struct == NULL)
	{
		ft_dprintf(2, ERR_MEMALLOC);
		ft_dprintf(2, " in ft_init asm_struct\n");
	}
	asm_struct->name = NULL;
	asm_struct->comment = NULL;
	asm_struct->code = NULL;
	asm_struct->parse = ft_memalloc(sizeof(t_parse));
	if (asm_struct->parse == NULL)
	{
		ft_dprintf(2, ERR_MEMALLOC);
		ft_dprintf(2, " in ft_init asm_struct\n");
	}
	asm_struct->parse->line = NULL;
	asm_struct->op_list = NULL;
	asm_struct->labels = NULL;
	asm_struct->parse->err_num = COMMON;
	return (asm_struct);
}
