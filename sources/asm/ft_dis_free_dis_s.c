//
// Created by Karina Semele on 11/24/20.
//

#include "asm.h"

int		ft_dis_free_ctruct(t_dis *dis_s)
{
	if (dis_s->file_s != NULL)
		free(dis_s->file_s);
	return (EXIT_SUCCESS);
}