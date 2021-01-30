/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:23:09 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

uint8_t	ft_get_arg_type(int8_t code)
{
	if (code == DIR_CODE)
		return (T_DIR);
	else if (code == REG_CODE)
		return (T_REG);
	else if (code == IND_CODE)
		return (T_IND);
	else
		return (0);
}
