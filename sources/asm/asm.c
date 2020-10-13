/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:45:40 by ksemele           #+#    #+#             */
/*   Updated: 2020/10/11 19:45:43 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_asm	*asm_struct;

	ft_printf("start asm! argc: %d\n", argc - 1);
	if (argc < 2)
		return (ft_print_help());
	// get all files from argv
	// parse && valide all files
	// if .s -> assemble all valide files to .cor
	// if .cor -> disassemble
	asm_struct = ft_init_asm_struct();
	if (!asm_struct)
		ft_asm_error(ASM_STRUCT_ERR, asm_struct);
	ft_check_read_argv_files(argc, argv, NULL);
	return (0);
}
