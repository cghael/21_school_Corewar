/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_statement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:30:05 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 12:30:07 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_elem	*ft_init_statement(void)
{
	t_elem *statement;

	if (!(statement = (t_elem *)ft_memalloc(sizeof(t_elem))))
		ft_terminate(ERR_STATEMENT_INIT);
	statement->op = NULL;
	statement->next = NULL;
	return (statement);
}
