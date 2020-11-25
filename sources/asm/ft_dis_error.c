/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:19:00 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 12:19:03 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_error(char *error_text, void *data_for_free)
{
	ft_dprintf(STDERR_FILENO, error_text);
	if (data_for_free != NULL)
		free(data_for_free);
	return (EXIT_FAILURE);
}
