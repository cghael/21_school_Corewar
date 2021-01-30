/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_label_exist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:46:26 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label			*ft_search_label_exist(t_asm *asm_s, char *name)
{
	t_label	*tmp;

	tmp = asm_s->labels;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
