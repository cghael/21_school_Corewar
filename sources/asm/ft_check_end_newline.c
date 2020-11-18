//
// Created by Cora Ghael on 11/17/20.
//
#include "asm.h"

int			ft_check_end_newline(t_asm *asm_s)
{
	char		buff[2];
	long int	res;

	if (lseek(asm_s->fd, -1, SEEK_END) < 0)
		return (EXIT_FAILURE);
	if (read(asm_s->fd, buff, 1) <= 0)
		return (EXIT_FAILURE);
	buff[1] = '\0';
	res = ft_strequ(buff, "\n");
	if (lseek(asm_s->fd, 0, SEEK_SET) < 0)
		return (EXIT_FAILURE);
	if (res == 1)
		asm_s->parse->endline = FALSE;
	else
		asm_s->parse->endline = TRUE;
	return (EXIT_SUCCESS);
}
