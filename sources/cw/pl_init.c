/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:55:51 by ablane            #+#    #+#             */
/*   Updated: 2020/11/26 12:46:04 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list		*pl_new_champ(int num_player)
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
	champion->exec_size = 0;
	player->content = (void*)champion;
	return (player);
}

int32_t		pl_bytecode_to_int32(uint8_t *buff, int len)
{
	int32_t res;
	int sign;
	int i;
	int k;

	i = 0;
	k = 0;
	res = 0;
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
	if (sign)
		res = ~(res);
	return (res);
}

void		pl_check_null_champ(int fd, int i)
{
	uint8_t buff[4];
	int32_t resul;
	int r;

	r = read(fd, &buff, 4);
	if (r != 4 || (resul = pl_bytecode_to_int32(buff, 4)))
	{
		if (i == 1)
			in_close_fd_err(fd, ERR_BAD_NULL_NAME);
		else
			in_close_fd_err(fd, ERR_BAD_NULL_COMM);
	}
}

void		pl_check_magic_header(int fd)
{
	uint8_t buff[COMMENT_LENGTH];
	int32_t resul;
	int r;

	r = read(fd, &buff, MAGIC_LEN);
	if (r != MAGIC_LEN ||
	(!(resul = pl_bytecode_to_int32(buff, MAGIC_LEN))) ||
	resul != COREWAR_EXEC_MAGIC)
		in_close_fd_err(fd, ERR_BAD_MAGIC);
}

void		pl_cp_char_len(uint8_t *buff, int len, t_list *player)
{
	while(len)
	{
		((t_player*)player->content)->name[len - 1] = buff[len - 1];
		len--;
	}
}

void		pl_cp_comment_champion(int fd, t_list *player)
{
	uint8_t buff[COMMENT_LENGTH];
	int r;

	r = read(fd, &buff, COMMENT_LENGTH);
	if (r == COMMENT_LENGTH)
		pl_cp_char_len(buff, COMMENT_LENGTH, player);
	else
		in_close_fd_err(fd, ERR_BAD_COMM);
}

void		pl_cp_name_champion(int fd, t_list *player)
{
	uint8_t buff[PROG_NAME_LENGTH];
	int r;

	r = read(fd, &buff, PROG_NAME_LENGTH);
	if (r == PROG_NAME_LENGTH)
		pl_cp_char_len(buff, PROG_NAME_LENGTH, player);
	else
		in_close_fd_err(fd, ERR_BAD_NAME);
}

void		pl_cp_exec_size(int fd, t_list *player)
{
	uint8_t buff[4];
	int32_t res;
	int r;

	r = read(fd, &buff, 4);
	if (r != 4)
		in_close_fd_err(fd, ERR_BAD_READ);
	res = pl_bytecode_to_int32(buff, 4);
	((t_player*)player->content)->exec_size = (unsigned int)res;
}

void		pl_cp_code_champion(int fd, t_list *player)
{
	uint8_t buff[((t_player*)player->content)->exec_size];

	int r;

	r = read(fd, &buff, ((t_player*)player->content)->exec_size);
	if (r == ((t_player*)player->content)->exec_size)
	{
		pl_cp_char_len(buff, ((t_player*)player->content)->exec_size, player);
		if (read(fd, &buff, 1))
			in_close_fd_err(fd, ERR_BAD_LEN);
	}
	else
		in_close_fd_err(fd, ERR_BAD_NAME);
}

void		pl_read_data_champion(char* file_name, t_list *player)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0777);
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
}

t_list		*pl_list_champions(int *i, char **av, t_list *champions)
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
	player = pl_new_champ(num_pl);
	pl_read_data_champion(av[*i], player);
	if(!champions)
		champions = player;
	else
		ft_lstadd(&champions, player);
	return (champions);
}

t_list		*pl_parsing_input(int ac, char **av)
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