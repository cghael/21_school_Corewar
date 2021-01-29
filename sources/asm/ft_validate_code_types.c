#include "asm.h"

void	ft_validate_code_types(t_dis *parser,
							   int8_t args_types_code,
							   int args_num)
{
	int		arg_num;
	int8_t	type;

	arg_num = 4;
	while (arg_num > args_num)
	{
		type = (int8_t)((args_types_code >> (2 * (4 - arg_num))) & 0x3);
		if (type != 0)
		{
			ft_code_types_warning((size_t) parser->pos);
			return ;
		}
		arg_num--;
	}
}
