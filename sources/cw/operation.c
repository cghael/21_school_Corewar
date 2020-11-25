/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:15:04 by esnowpea          #+#    #+#             */
/*   Updated: 2020/11/19 17:16:54 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lstpdelone(t_list **alst, t_list *del) //TODO add to libft
{
	t_list	*tmp;
	if (!alst || !(*alst) || !del)
		return ;
	if (*alst == del)
	{
		*alst = (*alst)->next;
		free(del);
		del = 0;
		return ;
	}
	else
	{
		tmp = *alst;
		while (tmp->next && tmp->next != del)
			tmp = tmp->next;
		tmp->next = del->next;
		free(del);
		del = 0;
		return ;
	}
}

int			vm_checkout(t_vm *vm)
{
	t_list	*tmp;

	tmp = vm->carriages;
	while (tmp)
	{
		if (vm->number_cycle - ((t_carriage*)tmp->content)->number_last_live
		<= vm->cycles_to_die || vm->cycles_to_die <= 0)
			ft_lstpdelone(&vm->carriages, tmp);
		tmp = tmp->next;
	}
	if (vm->number_live >= NBR_LIVE || vm->number_checks >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->number_checks = 0;
	}
	if (vm->carriages)
		return (1);
	else
		return (0);
}

t_player	*vm_operation(t_vm *vm)
{
	unsigned int	current;

	while (vm_checkout(vm))
	{
		current = 0;
		while (current < vm->cycles_to_die)
		{
			vm_survey_carriages(vm);
			current++;
		}
		vm->number_cycle += current;
		vm->number_checks++;
	}
	return (vm->last_live_player);
}