/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:55:51 by ablane            #+#    #+#             */
/*   Updated: 2020/11/25 16:32:11 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

int32_t pl_bytecode_to_int32(uint8_t *buff, int len) //todo VOID *res
{
//	void *res;
	int32_t res;
	int sign;
	int i;
	int k;

	i = 0;
	k = 0;
//	if(!(res = ft_memalloc(sizeof(char) * len)))
//		terminate(ERR_MALC_INIT);
	sign = (buff[0] & 0x80);
	while(len)
	{
		if(sign)
			res += (buff[len - 1] ^ 0xFF << (8 * k++));
		else
			res += (buff[len - 1] << (8 * k++));
		i++;
		len--;
	}
//	while(len)
//	{
//		if(sign)
//			(unsigned char*)res[i] = (buff[len - 1] ^ 0xFF << (8 * k++));
//		else
//			(unsigned char*)res[i] = (buff[len - 1] << (8 * k++));
//		i++;
//		len--;
//	}
	return (res);
}

void	pl_check_magic_header(int fd)
{
	uint8_t buff[COMMENT_LENGTH];
	int32_t resul;
	int r;

	r = 0;
	resul = COREWAR_EXEC_MAGIC; //todo: 0
	r = read(fd, &buff, MAGIC_LEN);
	if (r != MAGIC_LEN ||
	(!(resul = pl_bytecode_to_int32(buff, MAGIC_LEN))) ||
	resul != COREWAR_EXEC_MAGIC)
	{
		close(fd);
		terminate(ERR_BAD_MAGIC);
	}
}

void	pl_read_data_champion(char* file_name, t_list *player)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0777);
	if (fd < 0)
		terminate(ERR_BAD_FILE);
	pl_check_magic_header(fd);
	close(fd);
}

t_list *pl_list_champions(int *i, char **av, t_list *champions)
{
	t_list *player;
	int 	num_pl;

	player = NULL;
	num_pl = 0;
	while (!(ft_strstr(av[*i], ".cor")))
	{
		if (ft_strequ(av[*i], "-n")) //todo: проверить местоположение флага
			 // todo (возможно использование флага после аргумента имени)
			num_pl = ft_atoi(av[*++i]);
//		if (ft_strequ(av[*i], "-dump")) //todo: put other flags;
//		if (ft_strequ(av[*i], "-d")) //todo: put other flags;
		*i = *i + 1;
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

	i = 1;
	champions = NULL;
	if (ac < 2)
		terminate(USAGE);
	while (i < ac)
	{
		champions = pl_list_champions(&i, av, champions);
		i++;
	}
	return (champions);
}