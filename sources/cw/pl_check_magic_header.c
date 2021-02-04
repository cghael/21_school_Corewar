/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_check_magic_header.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:44:58 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "asm.h"

void		pl_check_null_champ(int fd, int i)
{
	int		r;
	uint8_t	buff[4];

	r = read(fd, &buff, 4);
	if (r != 4 || pl_bytecode_to_int32(buff, 4))
	{
		if (i == 1)
			in_close_fd_err(fd, ERR_BAD_NULL_NAME);
		else
			in_close_fd_err(fd, ERR_BAD_NULL_COMM);
	}
}

void		pl_check_magic_header(int fd)
{
	int		r;
	int32_t	resul;
	uint8_t	buff[MAGIC_LEN];

	r = read(fd, &buff, MAGIC_LEN);
	if (r != MAGIC_LEN ||
		(!(resul = pl_bytecode_to_int32(buff, MAGIC_LEN))) ||
		resul != COREWAR_EXEC_MAGIC)
		in_close_fd_err(fd, ERR_BAD_MAGIC);
}
