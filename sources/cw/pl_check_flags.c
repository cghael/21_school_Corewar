/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:26:09 by ablane            #+#    #+#             */
/*   Updated: 2021/02/03 15:33:01 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint32_t	fl_add_d(t_vm *vm, char **av, int i, int ac)
{
	if (i >= ac)
		err_flag('d');
	if (ft_atoi(av[i]) < 1 || vm->flag.dump || vm->flag.d)
		err_flag('d');
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
			if (vm->flag.v)
				err_flag('v');
			vm->flag.v = 1;
		}
		if (ft_strequ(av[i], "-a"))
		{
			if (vm->flag.a)
				err_flag('a');
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

int			pl_next_arg(char **av, int i, int ac)
{
	if (ft_strequ(av[i], "-d") || ft_strequ(av[i], "-dump"))
	{
		if (i + 1 >= ac)
			err_flag('d');
		if (av[i + 1][0] >= '0' && av[i + 1][0] <= '9')
			i = i + 2;
		else
			err_flag('d');
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
				err_flag('n');
		}
		else
			err_flag('n');
	}
	else
		err_flag('n');
	return (i);
}
