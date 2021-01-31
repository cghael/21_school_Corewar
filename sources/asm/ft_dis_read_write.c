/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_read_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:45:25 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_read_write(t_dis *dis_s)
{
	ft_dis_parse_bytecode(dis_s);
	ft_dis_validate_name(dis_s);
	ft_dis_validate_comment(dis_s);
	ft_dis_treat_exec_code(dis_s);
	ft_dis_write_file(dis_s);
	ft_printf("Writing output program to %s\n", dis_s->file_s);
	return (EXIT_SUCCESS);
}
