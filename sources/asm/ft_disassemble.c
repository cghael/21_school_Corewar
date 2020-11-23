//
// Created by leathertube on 12.10.2020.
//

#include "asm.h"

static t_dis	*ft_init_dis_struct(void)
{
	t_dis		*dis_s;

	dis_s = ft_memalloc(sizeof(t_dis*));
	return (dis_s);
}

static int		ft_open_disassemble_file(char *file, t_dis *dis_s, t_asm *asm_s)
{
	char		*dot;
	char		*tmp_name;
	char		*file_disassemble;

	dot = ft_strrchr(file, '.');
	if (!(tmp_name = ft_strsub(file, 0, dot - file + 1)))
	{
		ft_asm_error("Error in ft_disassemble()\n", asm_s);
		return (EXIT_FAILURE);
	}
	if (!(file_disassemble = ft_strjoin(tmp_name, "s")))
	{
		free(tmp_name);
		ft_asm_error("Error in ft_disassemble()\n", asm_s);
		return (EXIT_FAILURE);
	}
	free(tmp_name);

	dis_s->fd_cor = open(file_disassemble, \
								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	if (dis_s->fd_cor < 0)
	{
		free(file_disassemble);
		ft_asm_error("Error in ft_disassemble()\n", asm_s);
		return (EXIT_FAILURE);
	}
	free(file_disassemble);
	return (EXIT_SUCCESS);
}

void			ft_disassemble(char *file, t_asm *asm_s)
{

	t_dis		*dis_s;

	ft_printf("disassemble! [%s]\n", file);//todo del

	if (!(dis_s = ft_init_dis_struct()))
	{
		ft_asm_error("Error in ft_init_dis_struct", asm_s);
		return ;
	}
	if (EXIT_FAILURE == ft_open_disassemble_file(file, dis_s, asm_s))
	{
		ft_asm_error("Error in ft_open_disassemble_file()", asm_s);
		return ;
	}
	ft_printf("FD DISS_FILE [%d]\n", dis_s->fd_cor);
}