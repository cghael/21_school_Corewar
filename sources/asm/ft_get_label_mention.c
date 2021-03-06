/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_label_mention.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:23:26 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*ft_get_mention_name(t_asm *asm_s)
{
	char	*name;
	int		len;
	int		pos;

	len = 0;
	pos = asm_s->pos + 1;
	while (EXIT_SUCCESS == ft_is_label_char(asm_s->parse->line[pos]))
	{
		len++;
		pos++;
	}
	name = ft_memalloc(sizeof(char) * len + 1);
	if (name == NULL)
		return (NULL);
	name = ft_strncpy(name, &asm_s->parse->line[asm_s->pos + 1], len);
	return (name);
}

int				ft_get_label_mention(t_asm *asm_s, int arg_pars, int type)
{
	t_label *label;
	char	*name;

	name = ft_get_mention_name(asm_s);
	if (name == NULL)
		return (EXIT_FAILURE);
	asm_s->pos += ft_strlen(name) + 1;
	label = ft_search_label_exist(asm_s, name);
	if (label == NULL)
	{
		if (EXIT_FAILURE == ft_init_n_add_label(asm_s, name, 0))
			return (EXIT_FAILURE);
		label = asm_s->labels->last;
	}
	else
		free(name);
	if (EXIT_FAILURE == ft_init_n_add_mention(asm_s, arg_pars, label))
		return (EXIT_FAILURE);
	asm_s->op_list->last->args[arg_pars].type = type;
	return (EXIT_SUCCESS);
}
