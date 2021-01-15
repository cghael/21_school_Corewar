/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:37:24 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 12:37:24 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ld(t_carriage *car, t_vm *vm)
{
	set_array(car->args[1].data, car->args[0].data, REG_SIZE);
	if (ft_bytetoint(car->args[1].data, REG_SIZE) == 0)
		car->carry = 1;
	else
		car->carry = 0;
}