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

void			ft_choose_new_filename(char *file_disassemble, t_dis *dis_s, t_asm *asm_s)
{
	char		*answer;
	char		*new_filename;

	if (!(new_filename = ft_strnew(0)) || !(answer = ft_strnew(0)))
	{
		ft_dprintf(STDERR_FILENO, MEMALLOC_ERR);
		ft_asm_error("in ft_open_disassemble_file()\n", asm_s);
	}
	if ((dis_s->fd_cor = open(file_disassemble, O_RDONLY)) >= 0)
	{
		ft_printf("[%s] already exist\ninput new_filename:\n>>>\t", \
															file_disassemble);
		scanf("%s", new_filename);
		ft_printf("new_filename is [%s.s]\nit's correct? (Y/n)\n", \
																new_filename);
		scanf("%s", answer);
		while (1)
		{
			ft_printf("Wrong input\nnew_filename is [%s.s]\nit's correct?"
													" (Y/n)\n", new_filename);
			ft_bzero(answer, ft_strlen(answer));
			scanf("%s", answer);
			if (STRINGS_EQU == ft_strequ(answer, "n"))
			{
				ft_printf("[%s] already exist\ninput new_filename:\n>>>\t", \
															file_disassemble);
				ft_bzero(new_filename, ft_strlen(new_filename));
				scanf("%s", new_filename);
			}
			else if (STRINGS_EQU == ft_strequ(answer, "Y"))
			{
				ft_printf("new_filename is [%s.s]\n", new_filename);
				break ;
			}
		}
	}
	else
	{
		dis_s->fd_cor = open(file_disassemble, \
								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	}
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


	ft_choose_new_filename(file_disassemble, dis_s, asm_s);

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