/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read_argv_files.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:14:24 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 15:03:08 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_check_read_argv_files(int argc, char **argv)
{
	int		i;
	int		filename_res;
	t_asm	*asm_s;

	i = argc - 1;
	while (i > 0)
	{
		if (!(asm_s = ft_init_asm_struct()))
			ft_asm_error(ERR_ASM_STRUCT, NULL);
		else
		{
			filename_res = ft_is_filename(argv[i], asm_s);
			if (IS_S_FILE == filename_res)
				ft_assemble(argv[i], asm_s);
			else if (IS_COR_FILE == filename_res)
				ft_disassemble(argv[i], asm_s);
			else if (IS_BAD_FILE == filename_res)
				ft_dprintf(STDERR_FILENO, "invalid file [%s]\n", argv[i]);
			else if (IS_NOT_FILE == filename_res)
				ft_dprintf(STDERR_FILENO, "it's not file [%s]\n", argv[i]);
			if (asm_s != NULL)
				ft_free_asm_struct(asm_s);
		}
		i--;
	}
}
