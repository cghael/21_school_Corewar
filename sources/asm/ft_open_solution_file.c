/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_solution_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:57:09 by cghael            #+#    #+#             */
/*   Updated: 2020/10/13 18:57:11 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_open_solution_file(char *file, t_asm *asm_s)
{
	char	*dot;
	char	*tmp_name;
	char	*file_solution;

	dot = ft_strrchr(file, '.');

	if (!(tmp_name = ft_strsub(file, 0, dot - file + 1)))
		ft_asm_error("Error in ft_open_solution_file()\n", asm_s);
	if (!(file_solution = ft_strjoin(tmp_name, "cor")))
	{
		free(tmp_name);
		ft_asm_error("Error in ft_open_solution_file()\n", asm_s);
	}
	free(tmp_name);
	asm_s->fd_solution = open(file_solution, \
								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	if (asm_s->fd_solution < 0)
	{
		free(file_solution);
		ft_asm_error("Error in ft_open_solution_file()\n", asm_s);
	}
	free(file_solution);
}
