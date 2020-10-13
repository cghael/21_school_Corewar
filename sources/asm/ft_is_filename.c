//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

int ft_is_filename(char *filename, t_asm *asm_struct)
{
	asm_struct->fd = open(filename, O_RDONLY);
	if (asm_struct->fd < 0)
	{
		ft_printf("i can't open this file! [%s]\n", filename);
		return (IS_NOT_FILE);
	}
	if (STRINGS_EQU == ft_strequ(".s", ft_strrchr(filename, '.')))
	{
		ft_printf("[%s] is .s!\n", filename);
		return (IS_S_FILE);
	}
	if (STRINGS_EQU == ft_strequ(".cor", ft_strrchr(filename, '.')))
	{
		ft_printf("[%s] is .cor!\n", filename);
		return (IS_COR_FILE);
	}
	else
	{
		ft_printf("[%s] Bad file format!\n", filename);
		return (IS_BAD_FILE);
	}
}