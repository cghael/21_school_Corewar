/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_order_of_players.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:16:16 by ablane            #+#    #+#             */
/*   Updated: 2021/02/05 20:47:23 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list	*pl_swap(t_list *start, t_list *champ, t_list *tmp, t_list *prev)
{
	if (prev == champ)
	{
		champ->next = tmp->next;
		tmp->next = champ;
		champ = tmp;
		start = champ;
	}
	else
	{
		champ->next = tmp->next;
		tmp->next = champ;
		prev->next = tmp;
	}
	return (start);
}

t_list	*pl_sort_stack_champ(t_list *champions)
{
	t_list *start;
	t_list *prev;
	t_list *tmp;

	prev = champions;
	start = champions;
	while (champions && champions->next)
	{
		tmp = champions->next;
		if (((t_player*)champions->content)->number < ((t_player *)
				tmp->content)->number)
		{
			if (prev == champions)
				start = pl_swap(start, champions, tmp, prev);
			else
				start = pl_swap(start, champions, tmp, prev);
			champions = start;
		}
		else
		{
			prev = champions;
			champions = champions->next;
		}
	}
	return (start);
}
