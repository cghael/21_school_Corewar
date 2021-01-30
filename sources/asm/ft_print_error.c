/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:43:20 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:43:22 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_error(char *error, char *func, int line) //todo is need?
{
	ft_dprintf(2, "line %d:\n\t%s in %s()\n", line, error, func);
}
