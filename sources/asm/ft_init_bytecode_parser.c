/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bytecode_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:28:50 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 13:55:28 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_dis	*ft_init_bytecode_parser(int fd) //todo del???
{
	t_dis *parser;

	if (!(parser = (t_dis *)ft_memalloc(sizeof(t_dis))))
		ft_terminate(ERR_PARSER_INIT);
	parser->fd_cor = fd;
	parser->name = NULL;
	parser->comment = NULL;
	parser->code_size = 0;
	parser->code = NULL;
	parser->pos = 0;
	parser->elems = NULL;
	return (parser);
}
