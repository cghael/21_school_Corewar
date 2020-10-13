//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

void		ft_assemble(char *file, t_asm *asm_struct)
{
	ft_printf("assemble! %s\n", file);
	//valide file
	//if valid -> parse file -> translate to binary file:
	//create file with same name .cor
	ft_open_solution_file(file, asm_struct);
//	ft_write_bytecode_to_file(asm_struct->fd, asm_struct);
	close(asm_struct->fd);//todo err management?
	close(asm_struct->fd_solution);//todo err management?
}