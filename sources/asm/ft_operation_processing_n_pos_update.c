/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_processing_n_pos_update.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:40:34 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:40:35 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_args	*ft_add_args_array(t_typo num)
{
	t_args	*tmp;
	int		i;

	tmp = ft_memalloc(sizeof(t_args) * g_ops[num].n_args);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < g_ops[num].n_args)
	{
		tmp[i].content = NULL;
		i++;
	}
	return (tmp);
}

static int		ft_init_n_add_operation_token(t_asm *asm_s, t_typo num)
{
	t_operations	*tmp;
	t_operations	*begin;

	begin = asm_s->op_list;
	tmp = ft_memalloc(sizeof(t_operations));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	tmp->num = num;
	tmp->args = ft_add_args_array(num);
	if (tmp->args == NULL)
		return (EXIT_FAILURE);
	tmp->next = NULL;
	if (begin == NULL)
		asm_s->op_list = tmp;
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = tmp;
	}
	asm_s->op_list->last = tmp;
	return (EXIT_SUCCESS);
}

static int		ft_get_op_len(char *str)
{
	int		len;
	int		i;
	char	name[6];

	len = 0;
	ft_bzero(name, 6);
	while (str[len] && EXIT_FAILURE == ft_is_whitespace(str[len]) \
	&& EXIT_SUCCESS == ft_is_op_char(str[len]))
	{
		if (str[len] == 'r')
		{
			i = 0;
			ft_strncpy(name, str, len);
			while (i < COMMANDS_NUM)
			{
				if (ft_strequ(g_ops[i].name, name) == 1)
					return (len);
				i++;
			}
			ft_bzero(name, 6);
		}
		len++;
	}
	return (len);
}

static int		ft_is_valid_op_name(t_asm *asm_s)
{
	int		i;
	int		len;

	i = 0;
	len = ft_get_op_len(&asm_s->parse->line[asm_s->pos]);
	while (i < COMMANDS_NUM)
	{
		if (ft_strncmp(g_ops[i].name, &asm_s->parse->line[asm_s->pos], len) \
																		== 0)
		{
			if (EXIT_FAILURE == ft_init_n_add_operation_token(asm_s, i))
				return (EXIT_FAILURE);
			asm_s->pos += len;
			return (ft_check_n_write_op_args(asm_s, g_ops[i].n_args));
		}
		i++;
	}
	asm_s->parse->err_num = UNKNOWN_OPERATOR;
	return (EXIT_FAILURE);
}

int				ft_operation_processing_n_pos_update(t_asm *asm_s)
{
	while (asm_s->parse->line[asm_s->pos])
	{
		if (EXIT_SUCCESS == ft_is_whitespace(asm_s->parse->line[asm_s->pos]))
			asm_s->pos++;
		else if (asm_s->parse->line[asm_s->pos] == COMMENT_CHAR \
		|| asm_s->parse->line[asm_s->pos] == ALT_COMMENT_CHAR)
			break ;
		else if (EXIT_FAILURE == ft_is_valid_op_name(asm_s))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
