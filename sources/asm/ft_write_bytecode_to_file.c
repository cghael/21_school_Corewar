//
// Created by leathertube on 13.10.2020.
//
#include "asm.h"

void	int32_to_bytecode(char *data, int32_t pos, int32_t value, size_t size)
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
	len = MAGIC_LEN + PROG_NAME_LENGTH + END_SIZE + EXEC_SIZE + COMMENT_LENGTH \
											+ END_SIZE + asm_struct->exec_size;
	if (!(bytecode = ft_strnew((size_t)len)))
		ft_asm_error(ERR_WRITE_BYTE, asm_struct);
	int32_to_bytecode(bytecode, pos, COREWAR_EXEC_MAGIC, MAGIC_LEN);
	pos += MAGIC_LEN;
	ft_memcpy(&bytecode[pos], asm_struct->name, ft_strlen(asm_struct->name));
	pos += PROG_NAME_LENGTH;
	pos += END_SIZE;
	int32_to_bytecode(bytecode, pos, asm_struct->exec_size, EXEC_SIZE);
	pos += EXEC_SIZE;
	ft_memcpy(&bytecode[pos], asm_struct->comment, ft_strlen(asm_struct->comment));
	pos += COMMENT_LENGTH;
	pos += END_SIZE;
	ft_memcpy(&bytecode[pos], asm_struct->code, (size_t)asm_struct->exec_size);
	write(fd, bytecode, (size_t)len);
	free(bytecode);
}