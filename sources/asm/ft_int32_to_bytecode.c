//
// Created by Karina Semele on 10/13/20.
//

#include "asm.h"

void	ft_int32_to_bytecode(char *data, int32_t pos, int32_t val, size_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (uint8_t)((val >> i) & 0xFF);
		i += 8;
		size--;
	}
}
