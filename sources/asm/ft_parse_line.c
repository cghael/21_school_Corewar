/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:42:48 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:42:49 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_parse_line(t_asm *asm_s)
{
	asm_s->parse->res = ft_get_next_line(asm_s->fd, &asm_s->parse->line);
	asm_s->parse->n_line++;
	asm_s->pos = 0;
}
