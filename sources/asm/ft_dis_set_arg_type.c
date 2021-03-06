/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_set_arg_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:37:39 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 12:37:40 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_dis_set_arg_type(int8_t arg_code, int8_t index, t_elem *elem)
{
	elem->args_types[index - 1] = ft_dis_get_arg_type(arg_code);
}
