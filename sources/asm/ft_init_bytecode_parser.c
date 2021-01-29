#include "asm.h"

t_dis	*ft_init_bytecode_parser(int fd)
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
