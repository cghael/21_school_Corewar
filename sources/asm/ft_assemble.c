/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:00:48 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 15:03:08 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_asm_print(char *file)
{
	file[ft_strlen(file) - 2] = '\0';
	ft_printf("Writing output program to %s.cor\n", file);
}

int ft_assemble(char *file, t_asm *asm_s)
{
	if (PARSING_OK == ft_parse_file(asm_s))
	{
		ft_open_solution_file(file, asm_s);
		ft_write_bytecode_to_file(asm_s->fd_solution, asm_s);
		ft_asm_print(file);
	}
	if (close(asm_s->fd) < 0 || close(asm_s->fd_solution) < 0)
		return(ft_dprintf(STDERR_FILENO, ERR_CLOSE_FILE));
	else
		return (EXIT_SUCCESS);
}
