/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_set_arg_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:37:09 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 12:37:11 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_dis_set_arg_type(int8_t arg_code, int8_t index, t_elem *elems)
{
	elems->args[index - 1] = ft_dis_get_arg_type(arg_code);
}
