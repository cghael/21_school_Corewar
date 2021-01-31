/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_terminate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:24:41 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:24:42 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** func print error_text and exit with perror if it is.
*/

void	ft_dis_terminate(char *error_text)
{
	if (errno == 0)
		ft_dis_error(error_text, NULL);
	else
		perror(error_text);
	exit(1);
}