//
// Created by leathertube on 13.10.2020.
//
#include "asm.h"

void	int32_to_bytecode(char *data,
						  int32_t pos,
						  int32_t value,
						  size_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

void		ft_write_bytecode_to_file(int fd, t_asm *asm_struct)
{
	int32_t	len;
	int32_t	pos;
	char	*bytecode;

	pos = 0;
	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + asm_struct->pos;
	if (!(bytecode = ft_strnew((size_t)len)))
		ft_asm_error(ERR_WRITE_BYTE, asm_struct);
	int32_to_bytecode(bytecode, pos, COREWAR_EXEC_MAGIC, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], asm_struct->name, ft_strlen(asm_struct->name));
	pos += PROG_NAME_LENGTH;
	pos += 4;
	int32_to_bytecode(bytecode, pos, asm_struct->pos, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], asm_struct->comment, ft_strlen(asm_struct->comment));
	pos += COMMENT_LENGTH;
	pos += 4;
	ft_memcpy(&bytecode[pos], asm_struct->code, (size_t)asm_struct->pos);
	write(fd, bytecode, (size_t)len);
	free(bytecode);
}