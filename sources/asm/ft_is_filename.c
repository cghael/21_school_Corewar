//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

int			ft_is_filename(char *filename)
{
	int		res;
	int		fd;

	res = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("i can't open this file! [%s]\n", filename);
		res = -1;
		return (res);
	}
	if (STRINGS_EQU == ft_strequ(".s", ft_strrchr(filename, '.')))
	{
		ft_printf("[%s] is .s!\n", filename);
		res = 0;
		return (res);
	}
	if (STRINGS_EQU == ft_strequ(".cor", ft_strrchr(filename, '.')))
	{
		ft_printf("[%s] is .cor!\n", filename);
		res = 1;
		return (res);
	}
	else
	{
		ft_printf("[%s] Bad file format!\n", filename);
		res = 2;
	}
	return (res);
}