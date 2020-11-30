//
// Created by Karina Semele on 11/27/20.
//

#include "asm.h"

//todo refactor this to separate files, ERR_management?

int32_t			ft_dis_bytecode_to_int32(const uint8_t *bytecode, size_t size)
{
	int32_t		result;
	t_bool		sign;
	int			i;

	result = 0;
	sign = (t_bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

static int32_t	ft_dis_parse_int32(int fd)
{
	ssize_t		size;
	uint8_t		buffer[4];

	size = read(fd, &buffer, 4);
	if (size == -1)
		ft_dis_error(ERR_READ_FILE, NULL);
	if (size < 4)
		ft_dis_error(ERR_DIS_FILE_SIZE, NULL);
	return (ft_dis_bytecode_to_int32(buffer, 4));
}

static char		*ft_dis_parse_string(int fd, size_t len)
{
	ssize_t		size;
	char		*buffer;

	if (!(buffer = ft_strnew(len)))
		ft_dis_error(ERR_MEMALLOC, NULL);
	size = read(fd, buffer, len);
	if (size == -1)
		ft_dis_error(ERR_READ_FILE, NULL);
	if (size < (ssize_t)len)
		ft_dis_error(ERR_DIS_FILE_SIZE, NULL);
	return (buffer);
}

static uint8_t	*ft_dis_parse_code(int fd, size_t len)
{
	ssize_t		size;
	uint8_t		*buffer;
	uint8_t		byte;

	if (!(buffer = ft_memalloc(len)))
		ft_dis_error(ERR_MEMALLOC, NULL);
	size = read(fd, buffer, len);
	if (size == -1)
		ft_dis_error(ERR_READ_FILE, NULL);
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		ft_dis_error(ERR_DIS_FILE_SIZE, NULL);
	return (buffer);
}

int				ft_dis_parse_bytecode(t_dis *dis_s)
{
	if (ft_dis_parse_int32(dis_s->fd_cor) != COREWAR_EXEC_MAGIC)
		return (ft_dis_error(ERR_DIS_MAGIC, NULL));
	dis_s->name = ft_dis_parse_string(dis_s->fd_cor, PROG_NAME_LENGTH);
	if (ft_dis_parse_int32(dis_s->fd_cor) != 0)
		return (ft_dis_error(ERR_DIS_NO_NULL, NULL));
	if ((dis_s->code_size = ft_dis_parse_int32(dis_s->fd_cor)) < 0)
		return (ft_dis_error(ERR_DIS_CODE_SIZE, NULL));
	dis_s->comment = ft_dis_parse_string(dis_s->fd_cor, COMMENT_LENGTH);
	if (ft_dis_parse_int32(dis_s->fd_cor) != 0)
		return (ft_dis_error(ERR_DIS_NO_NULL, NULL));
	dis_s->code = ft_dis_parse_code(dis_s->fd_cor, (size_t) dis_s->code_size);
	ft_printf("\n\nname: [%s]\n\ncode: [%s]\n", dis_s->name, dis_s->code);//todo del
	return (EXIT_SUCCESS);
}

void					ft_dis_write_file(t_dis *dis_s)
{
	t_statement	*current;
	int i;
	ft_printf("try write parsed bot!\n");
	ft_dprintf(dis_s->fd_s, ".name \"%s\"\n", dis_s->name);
	ft_dprintf(dis_s->fd_s, ".comment \"%s\"\n\n", dis_s->comment);
	current = dis_s->statements;
	while (current)
	{
		ft_dprintf(dis_s->fd_s, "%s", current->op->name);
		i = 0;
		while (i < current->op->n_args)
		{
			if (current->args_types[i] == T_DIR)
				ft_dprintf(dis_s->fd_s, " %%%ld", (long)current->args[i]);
			else if (current->args_types[i] == T_IND)
				ft_dprintf(dis_s->fd_s, " %ld", (long)current->args[i]);
			else if (current->args_types[i] == T_REG)
				ft_dprintf(dis_s->fd_s, " r%ld", (long)current->args[i]);
			if (i < current->op->n_args - 1)
				ft_dprintf(dis_s->fd_s, ",");
			i++;
		}
		ft_dprintf(dis_s->fd_s, "\n");
		current = current->next;
	}
}

int				ft_dis_read_write(t_dis *dis_s)
{
	ft_dis_parse_bytecode(dis_s);
//	ft_dis_valide_name(dis_s);
//	ft_dis_valide_comment(dis_s);
	ft_dis_process_exec_code(dis_s);//todo what is it?
	ft_dis_write_file(dis_s);
	return (EXIT_SUCCESS);
}
