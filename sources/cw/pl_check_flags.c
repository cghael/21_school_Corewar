/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:26:09 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 11:55:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint32_t	fl_add_d(t_vm *vm, char **av, int i, int ac)
{
	if (i >= ac)
		terminate(ERR_DUMP);
	if (ft_atoi(av[i]) < 1 || vm->flag.dump || vm->flag.d)
		terminate(ERR_DUMP);
	return (ft_atoi(av[i]));
}

void		fl_check_flags(int ac, char **av, t_vm *vm)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-dump"))
			vm->flag.dump = fl_add_d(vm, av, ++i, ac);
		if (ft_strequ(av[i], "-d"))
			vm->flag.d = fl_add_d(vm, av, ++i, ac);
		if (ft_strequ(av[i], "-v"))
		{
			if (vm->flag.visual)
				terminate(ERR_FLAG_V);
			vm->flag.visual = 1;
		}
		if (ft_strequ(av[i], "-a"))
		{
			if (vm->flag.a)
				terminate(ERR_FLAG_A);
			vm->flag.a = 1;
		}
		i++;
	}
}

int			ft_compare_end(const char *str, const char *dest, int pos)
{
	int i;

	i = 0;
	if (pos < 1)
		return (0);
	while (str[pos])
	{
		if (str[pos] != dest[i])
			return (0);
		pos++;
		i++;
	}
	return (1);
}

int			pl_next_arg(char **av, int i, t_list *champions)
{
	if (champions)
		terminate(ERR_FLAG);
	if (ft_strequ(av[i], "-d") || ft_strequ(av[i], "-dump"))
	{
		if (av[i + 1][0] >= '0' && av[i + 1][0] <= '9')
			i = i + 2;
		else
			terminate(ERR_DUMP);
	}
	else if (ft_strequ(av[i], "-v") || ft_strequ(av[i], "-a"))
		i++;
	return (i);
}

int			fl_check_num_after_flag_n(char **av, int i, int ac, int *num_pl)
{
	if (i + 1 < ac)
	{
		i++;
		if (i < ac && av[i][0] >= '1' && av[i][0] <= '4')
		{
			*num_pl = ft_atoi(av[i++]);
			if (i >= ac || !(ft_strstr(av[i], ".cor")))
				terminate(ERR_FLAG_N);
		}
		else
			terminate(ERR_FLAG_N);
	}
	else
		terminate(ERR_FLAG_N);
	return (i);
}
