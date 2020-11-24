/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_init_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:19:20 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/24 12:19:23 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_dis	*ft_dis_init_struct(void)
{
	t_dis		*dis_s;

	dis_s = ft_memalloc(sizeof(t_dis*));
	dis_s->new_filename = NULL;
	return (dis_s);
}
