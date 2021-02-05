/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_error_free_dis_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:19:00 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 12:19:03 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_dis_error_free_dis_s(char *error_text, void *data_for_free, t_dis *dis_s)
{
	ft_dprintf(STDERR_FILENO, error_text);
	if (data_for_free != NULL)
		free(data_for_free);
	if (dis_s)
		ft_dis_free_struct(dis_s);
	return (EXIT_FAILURE);
}
