//
// Created by leathertube on 13.10.2020.
//
#include "asm.h"

void		ft_write_bytecode_to_file(int fd, t_asm *asm_s)
{
	int32_t	len;
	int32_t	pos;
	char	*bytecode;

	pos = 0;
	len = MAGIC_LEN + PROG_NAME_LENGTH + END_SIZE + EXEC_SIZE + COMMENT_LENGTH \
 + END_SIZE + asm_s->exec_size;
	if (!(bytecode = ft_strnew((size_t)len)))
	{
		ft_print_error(ERR_MEMALLOC, "ft_write_bytecode_to_file", 0);
		return ;
	}
	ft_int32_to_bytecode(bytecode, pos, COREWAR_EXEC_MAGIC, MAGIC_LEN);
	pos += MAGIC_LEN;
	ft_memcpy(&bytecode[pos], asm_s->name, ft_strlen(asm_s->name));
	pos += PROG_NAME_LENGTH + END_SIZE;
	ft_int32_to_bytecode(bytecode, pos, asm_s->exec_size, EXEC_SIZE);
	pos += EXEC_SIZE;
	ft_memcpy(&bytecode[pos], asm_s->comment, ft_strlen(asm_s->comment));
	pos += COMMENT_LENGTH + END_SIZE;
	ft_memcpy(&bytecode[pos], asm_s->code, (size_t)asm_s->exec_size); //todo SEGA!!!!
	write(fd, bytecode, (size_t)len);
	free(bytecode);
}