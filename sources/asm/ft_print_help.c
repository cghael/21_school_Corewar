/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:44:22 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:44:23 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_print_help(void)
{
	ft_printf("Usage: ./asm *.s *.cor\n");
	ft_printf("    *.s   —> from assemble to bytecode\n");
	ft_printf("    *.cor —> from bytecode to assemble\n");
	return (0);
}
