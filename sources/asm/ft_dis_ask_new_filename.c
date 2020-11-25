/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_ask_new_filename.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:08:06 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 19:08:07 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char *ft_dis_ask_new_filename(char *new_filename, t_dis *dis_s)
{
	scanf("%s", new_filename);
	if (!(new_filename = ft_strjoin(new_filename, ".s")))
	{
		ft_dis_error(ERR_DIS_CHOOSE, new_filename);
		return (NULL);
	}

	else
		return (new_filename);
}
