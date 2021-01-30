/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:55:51 by ablane            #+#    #+#             */
/*   Updated: 2021/01/30 18:47:13 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list		*pl_new_champ(int num_player)
{
	t_list		*player;
	t_player	*champion;

	champion = NULL;
	player = NULL;
	if (!(player = ft_lstnew(NULL, 0)))
		return (NULL);
	if (!(champion = (t_player*)malloc(sizeof(t_player))))
	{
		free(player);
		return (NULL);
	}
	champion->number = num_player;
	champion->exec_size = 0;
	player->content = champion;
	return (player);
}

t_list		*pl_read_data_champion(char *f_name, t_list *player, t_list *champs)
{
	int	fd;

	if (!ft_compare_end(f_name, ".cor", ft_strlen(f_name) - 4))
		terminate(ERR_BAD_NAME);
	fd = open(f_name, O_RDONLY, 0777);
	if (fd < 0)
		terminate(ERR_BAD_FILE);
	pl_check_magic_header(fd);
	pl_cp_name_champion(fd, player);
	pl_check_null_champ(fd, 1);
	pl_cp_exec_size(fd, player);
	pl_cp_comment_champion(fd, player);
	pl_check_null_champ(fd, 0);
	pl_cp_code_champion(fd, player);
	close(fd);
	if (!champs)
		champs = player;
	else
		player->next = champs;
	return (player);
}

t_list		*pl_list_champions(int ac, char **av, t_list *champions)
{
	int		i;
	int		num_pl;
	t_list	*player;

	i = 1;
	while (i < ac)
	{
		num_pl = 0;
		while (i < ac && !(ft_strstr(av[i], ".cor")))
		{
			if (ft_strequ(av[i], "-d") || ft_strequ(av[i], "-dump") ||
			ft_strequ(av[i], "-v") || ft_strequ(av[i], "-a"))
				i = pl_next_arg(av, i, ac, champions);
			else if (ft_strequ(av[i], "-n"))
				i = fl_check_num_after_flag_n(av, i, ac, &num_pl);
			else
				terminate(ERR_BAD_NAME);
		}
		if (i < ac && !(player = pl_new_champ(num_pl)))
			terminate(ERR_MALC_INIT);
		if (i < ac)
			champions = pl_read_data_champion(av[i++], player, champions);
	}
	return (champions);
}

t_list		*pl_order_of_players(t_list *champions)
{
	uint32_t	max_num;
	uint32_t	quant;
	t_list		*tmp;

	quant = 0;
	max_num = 0;
	tmp = champions;
	while (tmp)
	{
		if (max_num < ((t_player*)tmp->content)->number)
			max_num = ((t_player*)tmp->content)->number;
		tmp = tmp->next;
		quant++;
	}
	if (max_num > quant)
		terminate(ERR_FLAG_N);
	if (quant > MAX_PLAYERS)
		terminate(ERR_MANY_CHAMP);
	pl_number_order(champions, quant);
	champions = pl_sort_stack_champ(champions);
	pl_check_num_champion(champions);
	return (champions);
}

t_list		*pl_init_players(int ac, char **av)
{
	t_list	*champions;

	champions = NULL;
	if (ac < 2)
	{
		ft_printf(USAGE0 USAGE1 USAGE2 USAGE3 USAGE4 USAGE5 USAGE6 USAGE7
			USAGE8 USAGE9);
		exit(0);
	}
	champions = pl_list_champions(ac, av, champions);
	return (pl_order_of_players(champions));
}
