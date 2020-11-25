/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:55:51 by ablane            #+#    #+#             */
/*   Updated: 2020/11/25 13:35:50 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

t_list *pl_new_champ(int num_player)
{
	t_list	*player;
	t_player *champion;

	champion = NULL;
	player = NULL;
	if(!(player = ft_lstnew(NULL, 0)))
		terminate(ERR_MALC_INIT);
	if(!(champion = (t_player*)malloc(sizeof(t_player))))
		terminate(ERR_MALC_INIT);
	champion->number = num_player;
	player->content = (void*)champion;
	return (player);
}

void	pl_read_data_champion(char* file_name, t_list *player)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0777);
	if (fd < 0)
		terminate(ERR_BAD_FILE);
}

t_list *pl_list_champions(int *i, char **av, t_list *champions)
{
	t_list *player;
	int 	num_pl;

	player = NULL;
	num_pl = 0;
	while (!(ft_strstr(av[*i], ".cor")))
	{
		if (ft_strequ(av[*i], "-n"))
			num_pl = ft_atoi(av[*++i]);
//		if (ft_strequ(av[*i], "-dump")) //todo: put other flags;
//		if (ft_strequ(av[*i], "-d")) //todo: put other flags;
		*i++;
	}
	if (!(player = pl_new_champ(num_pl)))
		terminate(ERR_MALC_INIT);
	pl_read_data_champion(av[*i], player);
	if(!champions)
		champions = player;
	else
		ft_lstadd(&champions, player);
	return (champions);
}

t_list *pl_parsing_input(int ac, char **av)
{
	t_list	*champions;
	int		i;

	i = 0;
	champions = NULL;
	if (ac < 1)
		terminate(USAGE);
	while (i < ac)
	{
		champions = pl_list_champions(&i, av, champions);
	}
	return (champions);
}