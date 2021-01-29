#include "asm.h"

void	ft_name_warning(size_t pos)
{
	size_t prefix;

	prefix = 4;
	ft_dprintf(2, "Warning: Name was completed with not null bytes — [%zu]\n",
			   prefix + pos + 1);
}
