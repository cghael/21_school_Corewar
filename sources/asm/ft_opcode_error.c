#include "asm.h"

void	ft_op_code_error(t_dis *parser)
{
	int32_t	prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(2, "Incorrect operator code at %u byte\n",
			   prefix + parser->pos);
	exit(0);
}
