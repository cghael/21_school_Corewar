/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_order_of_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:37:51 by ablane            #+#    #+#             */
/*   Updated: 2021/01/30 12:48:00 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			pl_search_duplicate_num(t_list *champions, uint32_t quantity)
{
	t_list *tmp;

	tmp = champions;
	while (tmp)
	{
		if (((t_player*)tmp->content)->number == quantity && quantity > 0)
			quantity = pl_search_duplicate_num(champions, --quantity);
		tmp = tmp->next;
	}
	return (quantity);
}

void		pl_check_duplicate_num(t_list *champions)
{
	t_list *tmp;
	t_list *this;

	this = champions;
	while (this && this->next)
	{
		tmp = this->next;
		while (tmp)
		{
			if (((t_player*)this->content)->number
				== ((t_player*)tmp->content)->number
				|| ((t_player*)this->content)->number > MAX_PLAYERS
				|| ((t_player*)tmp->content)->number > MAX_PLAYERS)
				terminate(ERR_NUM_CHAMP);
			tmp = tmp->next;
		}
		this = this->next;
	}
}

void		pl_number_order(t_list *champions, int quant)
{
	t_list *tmp;

	tmp = champions;
	while (tmp)
	{
		quant = pl_search_duplicate_num(champions, quant);
		if (((t_player*)tmp->content)->number == 0)
			((t_player*)tmp->content)->number = quant--;
		tmp = tmp->next;
	}
	pl_check_duplicate_num(champions);
}

void		pl_check_num_champion(t_list *champions)
{
	int			max_num_player;
	t_list		*tmp;

	if (!champions)
		terminate(ERR_FEW_CHAMP);
	tmp = champions;
	max_num_player = (int)((t_player*)champions->content)->number;
	while (tmp)
	{
		if ((int)((t_player*)tmp->content)->number == max_num_player)
		{
			tmp = tmp->next;
			max_num_player--;
		}
		else
			terminate(ERR_NUM_CHAMP);
	}
}
