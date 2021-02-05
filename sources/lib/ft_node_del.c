/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:53:59 by cghael            #+#    #+#             */
/*   Updated: 2019/10/08 19:06:22 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_node_del(t_list **begin_list, t_list *node, void *n)
{
	t_list	*tmp;

	if (!*begin_list || !node)
		return (n);
	tmp = *begin_list;
	if (tmp == node)
		*begin_list = node->next;
	else
	{
		while (tmp->next != node)
			tmp = tmp->next;
		tmp->next = node->next;
	}
	if (node->content)
		free(node->content);
	node->next = NULL;
	free(node);
	node = NULL;
	return (n);
}
