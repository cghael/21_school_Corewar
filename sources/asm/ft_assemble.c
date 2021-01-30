/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:00:48 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:00:50 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_assemble(char *file, t_asm *asm_s)
{
	if (PARSING_OK == ft_parse_file(asm_s))
	{
		ft_open_solution_file(file, asm_s);
		ft_write_bytecode_to_file(asm_s->fd_solution, asm_s);
	}
	close(asm_s->fd); //todo if return -1 ERROR
	close(asm_s->fd_solution); //todo if return -1 ERROR
}
