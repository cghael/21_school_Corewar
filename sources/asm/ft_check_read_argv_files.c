//
// Created by leathertube on 12.10.2020.
//
#include "asm.h"

void	ft_check_read_argv_files(int argc, char **argv)
{
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		if (IS_S_FILE == ft_is_filename(argv[i]))
			ft_assemble(argv[i], NULL);
		else if (IS_COR_FILE == ft_is_filename(argv[i]))
			ft_disassemble(argv[i]);
		else if (IS_BAD_FILE == ft_is_filename(argv[i]))
			ft_dprintf(2, "invalid file [%s]\n", argv[i]);
		else if (IS_NOT_FILE == ft_is_filename(argv[i]))
			ft_dprintf(2, "is not file [%s]\n", argv[i]);
//		ft_printf("i %d\n", i);
		i--;
	}
}
