/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_ask_new_filename.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:08:06 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_dis_ask_new_filename(t_dis *dis_s)
{
	scanf("%s", dis_s->file_s);
	if (EXIT_FAILURE == ft_dis_add_s(dis_s))
		ft_dis_error(ERR_DIS_CHOOSE, dis_s->file_s);
}
