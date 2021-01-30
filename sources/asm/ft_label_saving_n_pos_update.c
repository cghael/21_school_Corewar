/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label_saving_n_pos_update.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:33:20 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:33:22 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_warning_if_label_exist(t_asm *asm_s, char *content)
{
	t_label	*begin;
	int		pos;

	pos = asm_s->pos - (int)ft_strlen(content) - 1;
	begin = asm_s->labels;
	while (begin)
	{
		if (TRUE == ft_strequ(content, begin->name) && begin->n_line)
		{
			asm_s->parse->err_num = DOUBLE_LABEL;
			ft_dprintf(2, "!WARNING! IN LINE \e[1;33m[%d, %d]:\e[m%s\n\n" \
			"\e[1;34m%*cへ(⊙︿⊙)< it's not OK!\e[m\n\e[1;13m%s\n\n", \
			asm_s->parse->n_line, pos, \
			g_error[(int)asm_s->parse->err_num], pos, \
			'v', asm_s->parse->line);
			free(content);
			return (EXIT_FAILURE);
		}
		begin = begin->next;
	}
	return (EXIT_SUCCESS);
}

static char	*ft_get_label_name(t_asm *asm_s, const char *colon)
{
	char	*tmp;
	int		len;
	int		i;

	len = (int)(colon - &asm_s->parse->line[asm_s->pos]);
	i = asm_s->pos;
	while (i < len)
	{
		if (EXIT_FAILURE == ft_is_label_char(asm_s->parse->line[i]))
		{
			asm_s->parse->err_num = LEXICAL_ERROR;
			asm_s->pos = i;
			return (NULL);
		}
		i++;
	}
	tmp = (char*)ft_memalloc(sizeof(char) * len + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_strncpy(tmp, &asm_s->parse->line[asm_s->pos], len);
	asm_s->pos += len + 1;
	return (tmp);
}

int			ft_label_saving_n_pos_update(t_asm *asm_s, char *colon)
{
	char	*content;
	t_label	*tmp;

	content = ft_get_label_name(asm_s, colon);
	if (content == NULL)
		return (EXIT_FAILURE);
	if (EXIT_SUCCESS == ft_warning_if_label_exist(asm_s, content))
	{
		if ((tmp = ft_search_label_exist(asm_s, content)) != NULL)
		{
			tmp->n_line = asm_s->parse->n_line;
			tmp->byte_pos = asm_s->exec_size;
			free(content);
			return (EXIT_SUCCESS);
		}
		if (EXIT_FAILURE == ft_init_n_add_label(asm_s, content, \
														asm_s->parse->n_line))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
