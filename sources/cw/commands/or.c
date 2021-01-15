/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:37:46 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 12:37:46 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		or(t_carriage *car, t_vm *vm)
{
	int32_t		num;

	num = ft_bytetoint(car->args[0].data, REG_SIZE) |
		  ft_bytetoint(car->args[1].data, REG_SIZE);
	ft_inttobyte(num, car->args[2].data, REG_SIZE);
	if (ft_bytetoint(car->args[2].data, REG_SIZE) == 0)
		car->carry = 1;
	else
		car->carry = 0;
}