//
// Created by Karina Semele on 11/30/20.
//

#include "asm.h"

void	ft_dis_valide_name(t_dis *dis_s)
{
	size_t i;

	i = ft_strlen(dis_s->name);
	while (i < PROG_NAME_LENGTH)
	{
		if (dis_s->name[i])
		{
			ft_dis_error(ERR_VALIDE_NAME, NULL);
			return ;
		}
		i++;
	}
}

void	ft_dis_valide_comment(t_dis *dis_s)
{
	size_t i;

	i = ft_strlen(dis_s->comment);
	while (i < COMMENT_LENGTH)
	{
		if (dis_s->comment[i])
		{
			ft_dis_error(ERR_VALIDE_COMMENT, NULL);
			return ;
		}
		i++;
	}
}

void	validate_types_code(t_dis *dis_s,
							int8_t is_args_type,
							int n_args)
{
	int		arg_num;
	int8_t	type;

	arg_num = 4;
	while (arg_num > n_args)
	{
		type = (int8_t)((is_args_type >> (2 * (4 - arg_num))) & 0x3);
		if (type != 0)
		{
			ft_dis_error(ERR_VALIDE_TYPES, NULL);
			return ;
		}
		arg_num--;
	}
}

t_bool	is_arg_types_valid(t_statement *statements)
{
	int32_t i;

	i = 0;
	while (i < statements->op->n_args)
	{
		if (!(statements->args_types[i] & statements->op->args[i]))
			return (false);
		i++;
	}
	return (true);
}



void	add_statement(t_statement **list, t_statement *new)
{
	t_statement *current;

	if (list)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*list = new;
	}
}

static uint8_t	get_arg_type(int8_t code)
{
	if (code == DIR_CODE)
		return (T_DIR);
	else if (code == REG_CODE)
		return (T_REG);
	else if (code == IND_CODE)
		return (T_IND);
	else
		return (0);
}

static void		set_arg_type(int8_t arg_code,
								int8_t index,
								t_statement *statements)
{
	statements->args[index - 1] = get_arg_type(arg_code);
}

void			process_arg_types(t_dis *dis_s, t_statement *statements)
{
	int8_t is_args_type;

	if (statements->op->is_args_type)
	{
		is_args_type = dis_s->code[dis_s->pos];
		if (statements->op->n_args >= 1)
			set_arg_type((int8_t)((is_args_type & 0xC0) >> 6), 1, statements);
		if (statements->op->n_args >= 2)
			set_arg_type((int8_t)((is_args_type & 0x30) >> 4), 2, statements);
		if (statements->op->n_args >= 3)
			set_arg_type((int8_t)((is_args_type & 0xC) >> 2), 3, statements);
		validate_types_code(dis_s, is_args_type, statements->op->n_args);
	}
	else
		statements->args_types[0] = statements->op->args[0];
}



static size_t		get_size(t_statement *statements, unsigned i)
{
	if (statements->args[i] == T_REG)
		return (1);
	else if (statements->args[i] == T_IND)
		return (IND_SIZE);
	else
		return (statements->op->t_dir_size);
}

static void			process_arg(t_dis *dis_s,
								   t_statement *statements,
								   unsigned i)
{
	size_t size;

	size = get_size(statements, i);
	if (dis_s->code_size - dis_s->pos >= (int32_t)size)
	{
		statements->args[i] = ft_dis_bytecode_to_int32(&dis_s->code[dis_s->pos],
											   size);
		dis_s->pos += size;
		if (statements->args[i] == T_REG && statements->args[i] <= 0)
			ft_dis_error(ERR_DIS, NULL);//todo add right func
//			register_error(dis_s);
	}
	else
		ft_dis_error(ERR_DIS, NULL);//todo add right func
//		length_error(dis_s);
}

static void			process_args(t_dis *dis_s, t_statement *statements)
{
	unsigned i;

	i = 0;
	while (i < statements->op->n_args)
	{
		process_arg(dis_s, statements, i);
		i++;
	}
}

t_statement	*init_statement(void)
{
	t_statement *statements;

	if (!(statements = (t_statement *)ft_memalloc(sizeof(t_statement))))
		ft_dis_error(ERR_DIS_STATEMENT, NULL);
	statements->op = NULL;
	statements->next = NULL;
	return (statements);
}

static t_statement	*ft_dis_process_statement(t_dis *dis_s)
{
	t_statement	*new_statement;
	uint8_t		op_code;

	new_statement = init_statement();
	op_code = dis_s->code[dis_s->pos];
	if (op_code >= 0x01 && op_code <= 0x10)
	{
		dis_s->pos++;
		new_statement->op = &g_ops[op_code - 1];//присваивание из g_ops[]
		if (new_statement->op->is_args_type && dis_s->pos >= dis_s->code_size)
			ft_dis_error(ERR_DIS_LEN_CODE, NULL);//todo add right func
		process_arg_types(dis_s, new_statement);
		if (is_arg_types_valid(new_statement))
		{
			if (new_statement->op->is_args_type)
				dis_s->pos++;
			process_args(dis_s, new_statement);
		}
		else
			ft_dis_error(ERR_DIS, NULL);//todo add right func
//			arg_types_code_error(dis_s);
	}
	else
		ft_dis_error(ERR_DIS, NULL);//todo add right func
//		op_code_error(dis_s);
	return (new_statement);
}


void					ft_dis_process_exec_code(t_dis *dis_s)
{
	while (dis_s->pos < dis_s->code_size)
	{
		add_statement(&(dis_s->statements), ft_dis_process_statement(dis_s));
	}
}