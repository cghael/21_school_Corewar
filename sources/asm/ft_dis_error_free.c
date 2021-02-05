/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_error_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:58:26 by ksemele           #+#    #+#             */
/*   Updated: 2021/02/05 15:58:27 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_error_free(char *error_text, void *data_for_free, t_dis *dis_s)
{
	ft_dprintf(STDERR_FILENO, error_text);
	if (data_for_free != NULL)
		free(data_for_free);
	if (dis_s)
		ft_dis_free_struct(dis_s);
	return (EXIT_FAILURE);
}
