//
// Created by leathertube on 12.10.2020.
//
#include "asm.h"

void ft_check_read_argv_files(int argc, char **argv)
{
	int		i;
	int		filename_res;
	t_asm	*asm_s;

	i = argc - 1;
	while (i > 0)
	{
		if (!(asm_s = ft_init_asm_struct()))
			ft_asm_error(ASM_STRUCT_ERR, NULL);
		else
		{
			filename_res = ft_is_filename(argv[i], asm_s);
			if (IS_S_FILE == filename_res)
				ft_assemble(argv[i], asm_s);
			else if (IS_COR_FILE == filename_res)
				ft_disassemble(argv[i], asm_s);
			else if (IS_BAD_FILE == filename_res)
				ft_dprintf(2, "invalid file [%s]\n", argv[i]);
			else if (IS_NOT_FILE == filename_res)
				ft_dprintf(2, "is not file [%s]\n", argv[i]);
			if (asm_s != NULL)
				ft_free_asm_struct(asm_s);
		}
		i--;
	}
}
