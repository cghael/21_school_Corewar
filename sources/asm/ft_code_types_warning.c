
#include "asm.h"

void	ft_code_types_warning(size_t pos)
{
	size_t prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(2, "Warning: Insignificant bits in code of arguments types are"\
									" not null — [%zu]\n", prefix + pos + 1);
}
