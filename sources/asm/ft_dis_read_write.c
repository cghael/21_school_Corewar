/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis_read_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:45:25 by ksemele           #+#    #+#             */
/*   Updated: 2021/01/31 13:48:32 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_dis_read_write(t_dis *dis_s)
{
	//todo REFACTOR! all to new code
	ft_parse_bytecode(dis_s);
	ft_validate_name(dis_s);
	ft_validate_comment(dis_s);
	ft_process_exec_code(dis_s);

	ft_dprintf(2, "parser: %s\n%s\n", dis_s->name, dis_s->comment);//todo del
	ft_dis_write_file(dis_s);
	return (EXIT_SUCCESS);
}
