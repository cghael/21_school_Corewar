/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_convert_start_filename.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:22:06 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 16:22:08 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_convert_start_filename(char *file, t_dis *dis_s)
{
	if (EXIT_FAILURE == ft_dis_copy_filename(file, dis_s) \
		|| EXIT_FAILURE == ft_dis_del_cor(dis_s) \
		|| EXIT_FAILURE == ft_dis_add_s(dis_s))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
