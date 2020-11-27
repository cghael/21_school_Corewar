/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_free_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:23:49 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 18:23:53 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_free_struct(t_dis *dis_s)
{
	if (dis_s->file_s != NULL)
		free(dis_s->file_s);
	return (EXIT_SUCCESS);
}
