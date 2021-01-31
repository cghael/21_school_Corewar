/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:59:48 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 11:59:50 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_asm_error_no_label(t_asm *asm_s)
{
	if (asm_s != NULL)
	{
		ft_dprintf(STDERR_FILENO, "\e[1;31mERROR IN LINE " \
							"\e[1;33m[%d, %d]:\e[m%s%s" \
							"\e[1;34m (ಠ╭╮ಠ)< fix it!\e[m\n\e[1;13m\n", \
			asm_s->labels->mention->n_line, asm_s->labels->mention->pos, \
			g_error[(int)asm_s->parse->err_num], asm_s->labels->name);
	}
}

void	ft_asm_error_in_line(t_asm *asm_s)
{
	if (asm_s != NULL)
	{
		ft_dprintf(STDERR_FILENO, "\e[1;31mERROR IN LINE " \
						"\e[1;33m[%d, %d]:\e[m%s\n\n" \
						"\e[1;34m%*cへ(ಠ╭╮ಠ)< fix it!\e[m\n\e[1;13m%s\n\n", \
			asm_s->parse->n_line, asm_s->pos + 1, \
			g_error[(int)asm_s->parse->err_num], asm_s->pos + 1, \
			'v', asm_s->parse->line);
	}
}

void	ft_asm_error(char *error_text, t_asm *asm_s)
{
	ft_dprintf(STDERR_FILENO, "ERROR ______________ %s\n", error_text);
	if (asm_s)
		ft_free_asm_struct(asm_s);
	asm_s = NULL;
}
