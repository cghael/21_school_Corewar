/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:37:55 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 12:37:55 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_carriage *car, t_vm *vm)
{
	int		i;

	(void)vm;
	set_array(car->args[1].data, car->args[0].data, REG_SIZE);
	i = 0;
	while (i < REG_SIZE)
	{
		car->args[1].data.data[(car->args[1].data.pos + i) %
		car->args[1].data.max].num_player = car->player->number;
		i++;
	}
}
