//
// Created by Cora Ghael on 11/17/20.
//
#include "asm.h"

static int	ft_init_n_add_label(t_asm *asm_s, const char *name)
{
	t_label	*tmp;
	t_label	*begin;

	tmp = (t_label*)ft_memalloc(sizeof(t_label));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	tmp->next = NULL;
	tmp->name = name;
	begin = asm_s->labels;
	if (begin == NULL)
		asm_s->labels = tmp;
	else
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = tmp;
	}
	asm_s->labels->last = tmp;
	return (EXIT_SUCCESS);
}

static void	ft_warning_if_label_exist(t_asm *asm_s, char *content)
{
	t_label	*begin;
	int		pos;

	pos = asm_s->pos - (int)ft_strlen(content) - 1;
	begin = asm_s->labels;
	while (begin)
	{
		if (TRUE == ft_strequ(content, begin->name))
		{
			asm_s->parse->err_num = DOUBLE_LABEL;
			ft_dprintf(2, "!WARNING! IN LINE \e[1;33m[%d, %d]:\e[m%s\n\n" \
			"\e[1;34m%*cへ(⊙︿⊙)< it's not OK!\e[m\n\e[1;13m%s\n\n", \
			asm_s->parse->n_line, pos, \
			g_error[(int)asm_s->parse->err_num], pos, \
			'v', asm_s->parse->line);
		}
		begin = begin->next;
	}
}

static char	*ft_get_label_name(t_asm *asm_s, const char *colon)
{
	char	*tmp;
	int		len;

	len = (int)(colon - &asm_s->parse->line[asm_s->pos]);
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

	content = ft_get_label_name(asm_s, colon);
	if (content == NULL)
		return (EXIT_FAILURE);
	if (EXIT_FAILURE == ft_init_n_add_token(asm_s, LABEL, content))
		return (EXIT_FAILURE);
	ft_warning_if_label_exist(asm_s, content);
	if (EXIT_FAILURE == ft_init_n_add_label(asm_s, content))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
