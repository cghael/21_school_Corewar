//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void		ft_assemble(char *file, t_asm *asm_s)
{
	ft_printf("assemble! %s\n", file);
	//valide file in parsing -> if not valid -> print error, stop assembling
	if (PARSING_OK == ft_parse_file(asm_s))
	//if valid -> parse file -> translate to binary file:
	{
		ft_printf("\nNAME = [%s]\nCOMMENT = [%s]\n", asm_s->name, asm_s->comment);
		ft_open_solution_file(file, asm_s);
//		ft_print_error(MEMALLOC_ERR, "ft_write_bytecode_to_file", 15);// todo delete
//		ft_write_bytecode_to_file(asm_s->fd_solution, asm_s);//todo my penis is big
	}
	close(asm_s->fd);//todo err management?
	close(asm_s->fd_solution);//todo err management?
}