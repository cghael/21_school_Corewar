/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_solution_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:57:09 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:56:53 by ablane           ###   ########.fr       */
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
		ft_asm_error(ERR_DIS_OPEN_SOL, asm_s);
	if (!(file_solution = ft_strjoin(tmp_name, "cor")))
	{
		free(tmp_name);
		ft_asm_error(ERR_DIS_OPEN_SOL, asm_s);
		return ;
	}
	free(tmp_name);
	asm_s->fd_solution = open(file_solution, \
								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	if (asm_s->fd_solution < 0)
	{
		free(file_solution);
		ft_asm_error(ERR_DIS_OPEN_SOL, asm_s);
		return ;
	}
	free(file_solution);
}
