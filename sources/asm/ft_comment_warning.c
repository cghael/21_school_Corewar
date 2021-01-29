//
// Created by Karina Semele on 1/27/21.
//

#include "asm.h"

void	ft_comment_warning(size_t pos)
{
	size_t prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4;
	ft_dprintf(2, "Warning: Comment was completed with not null bytes"\
												" — [%zu]\n", prefix + pos + 1);
}
