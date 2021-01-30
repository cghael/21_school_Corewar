#include "asm.h"

/*
** func treating all elems by a args_type
*/

t_elem			*ft_args_treat(t_dis *dis_s)
{
	t_elem		*elem;
	uint8_t		opcode;

	elem = ft_init_element();
	opcode = dis_s->code[dis_s->pos];
	if (opcode >= 0x01 && opcode <= 0x10)
	{
		dis_s->pos++;
		elem->op = &g_ops[opcode - 1];
		if (elem->op->is_args_type && dis_s->pos >= dis_s->code_size)
			ft_dis_length_error(dis_s);
		ft_dis_treat_arg_types(dis_s, elem);
		if (ft_is_arg_types_valide(elem))
		{
			if (elem->op->is_args_type)
				dis_s->pos++;
			ft_process_args(dis_s, elem);
		}
		else
			ft_arg_types_code_error(dis_s);
	}
	else
		ft_op_code_error(dis_s);
	return (elem);
}
