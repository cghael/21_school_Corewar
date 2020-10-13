//
// Created by leathertube on 12.10.2020.
//
#include "asm.h"

void ft_check_read_argv_files(int argc, char **argv, t_asm *asm_struct)
{
	int		i;
	int		filename_res;

	i = argc - 1;
	while (i > 0)
	{
		filename_res = ft_is_filename(argv[i], asm_struct);
		if (IS_S_FILE == filename_res)
			ft_assemble(argv[i], asm_struct);
		else if (IS_COR_FILE == filename_res)
			ft_disassemble(argv[i], asm_struct);
		else if (IS_BAD_FILE == filename_res)
			ft_dprintf(2, "invalid file [%s]\n", argv[i]);
		else if (IS_NOT_FILE == filename_res)
			ft_dprintf(2, "is not file [%s]\n", argv[i]);
		i--;
	}
}
