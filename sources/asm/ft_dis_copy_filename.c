/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_copy_filename.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:42:23 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/25 13:42:26 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_copy_filename(char *filename, t_dis *dis_s)
{
	ft_strdel(&dis_s->file_s);
	if (!(dis_s->file_s = ft_strdup(filename)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
