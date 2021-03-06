/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:38:30 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 12:38:30 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		zjmp(t_carriage *car, t_vm *vm)
{
	if (car->carry == 1)
	{
		car->position += (((int16_t)ft_bytetoint(car->args[0].data, IND_SIZE)) %
				IDX_MOD);
		while (car->position < 0)
			car->position += MEM_SIZE;
		car->position %= MEM_SIZE;
	}
	else
		car->position = (car->position + len_args(car, vm)) % MEM_SIZE;
}
