/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disassemble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:05:47 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/23 16:05:51 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_dis	*ft_init_dis_struct(void)
{
	t_dis		*dis_s;

	dis_s = ft_memalloc(sizeof(t_dis*));
	dis_s->new_filename = NULL;
	return (dis_s);
}

static void		ft_correct_input(char *answer, char *file_disassemble, \
										char *new_filename, t_dis *dis_s)
{
	while (1)
	{
		if (STRINGS_EQU == ft_strequ(answer, "n"))
		{
			ft_printf(FILE_EXIST, file_disassemble);
			ft_bzero(new_filename, ft_strlen(new_filename));
			scanf("%s", new_filename);
		}
		else if (STRINGS_EQU == ft_strequ(answer, "Y"))
		{
			ft_printf("new_filename is [%s.s]\n", new_filename);
			if (dis_s->new_filename != NULL)
				free(dis_s->new_filename);
			dis_s->new_filename = ft_strdup(new_filename);
			if ((open(dis_s->new_filename, O_RDONLY)) >= 0)
				ft_printf(FILE_EXIST, dis_s->new_filename);
//			dis_s->fd_cor = open(new_filename, \
//								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
			break ;
		}
		ft_printf(WRONG_SCANF_INPUT _IS_CORRECT, new_filename);
		ft_bzero(answer, ft_strlen(answer));
		scanf("%s", answer);
	}
}

void			ft_choose_new_filename(char *file_disassemble, t_dis *dis_s)
{
	char		*answer;
	char		*new_filename;

	new_filename = ft_strnew(0);
	answer = ft_strnew(0);
	if (!new_filename || !answer)
		ft_dis_error(ERR_DIS_CHOOSE, NULL);
//		ft_asm_error("in ft_disassemble_file()\n", asm_s);//todo -> dis_err
//	if ((dis_s->fd_cor = open(file_disassemble, O_RDONLY)) >= 0)//todo hmmm?
	if ((open(file_disassemble, O_RDONLY)) >= 0)
	{
		ft_printf(FILE_EXIST, file_disassemble);
		scanf("%s", new_filename);
		if (STRINGS_EQU != ft_strequ(answer, "Y"))
		{
			ft_printf(Q_CORRECT_NAME, new_filename);
			scanf("%s", answer);
			ft_correct_input(answer, file_disassemble, new_filename, dis_s);
		}
	}
	else
	{
		ft_printf("i cant OPEN FILE_DISSSS!!!!!!!\n");
		dis_s->new_filename = ft_strdup(file_disassemble);
//		dis_s->fd_cor = open(file_disassemble, \
//								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	}
}

static int ft_disassemble_file(char *file, t_dis *dis_s)
{
	char		*dot;
	char		*tmp_name;
	char		*file_disassemble;

	dot = ft_strrchr(file, '.');
	if (!(tmp_name = ft_strsub(file, 0, dot - file)))
	{
//		ft_asm_error("Error in ft_disassemble()\n", asm_s);//todo -> dis_err
		return (EXIT_FAILURE);
	}
	ft_printf("tmp_name [%s]\n", tmp_name);//todo del
	if (!(file_disassemble = ft_strjoin(tmp_name, ".s")))
		return (ft_dis_error(ERR_DIS_FILE, tmp_name));

	ft_printf("file_diss [%s]\n", file_disassemble);//todo del
	ft_choose_new_filename(file_disassemble, dis_s);
	if (!(dis_s->new_filename = ft_strjoin(dis_s->new_filename, ".s")))
	{
		free(dis_s->new_filename);
		return (ft_dis_error(ERR_DIS_FILE, tmp_name));
	}
	if (dis_s->fd_cor < 0)
	{
		free(file_disassemble);
//		ft_asm_error("Error in ft_disassemble()\n", asm_s);//todo dis_err
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
	if (EXIT_FAILURE == ft_disassemble_file(file, dis_s))
	{
		ft_asm_error("Error in ft_disassemble_file()", asm_s);
		return ;
	}
	ft_printf("FD [%d] filename [%s]\n", dis_s->fd_cor, dis_s->new_filename);//todo del debug
	dis_s->fd_cor = open(dis_s->new_filename, \
								O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);//todo must be in finally
}
