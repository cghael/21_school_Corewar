/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:54:45 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_process_exec_code(t_dis *parser)
{
	while (parser->pos < parser->code_size)
		ft_add_statement(&(parser->elems), ft_process_statement(parser));
}
