#include "asm.h"
//
//void	disassemble(char *filename)
//{
//	int			fd;
//	t_dis	*parser;
//
//	if ((fd = open(filename, O_RDONLY)) == -1)
//		ft_terminate(ERR_OPEN_FILE);
//	parser = ft_init_bytecode_parser(fd);
//
//	ft_parse_bytecode(parser);
//	ft_validate_name(parser);
//	ft_validate_comment(parser);
//	ft_process_exec_code(parser);
//
//	filename = ft_replace_extension(filename, ".cor", ".s");
//	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
//		ft_terminate(ERR_CREATE_FILE);
//
//	ft_write_asm_file(fd, parser);
//	ft_printf("Writing output program to %s\n", filename);
//
//	ft_strdel(&filename);
//	ft_free_bytecode_parser(&parser);
//}
