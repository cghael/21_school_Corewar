/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:55:51 by ablane            #+#    #+#             */
/*   Updated: 2020/12/02 15:35:24 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		fl_check_flags(int ac, char** av, t_vm *vm)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-dump"))
		{
			if (ft_atoi(av[++i]) < 1)
				terminate(USAGE_DUMP);
			vm->flag.dump = ft_atoi(av[++i]);
		}
		if (ft_strequ(av[i], "-d"))
		{
			if (ft_atoi(av[++i]) < 1)
				terminate(USAGE_DUMP);
			vm->flag.d = ft_atoi(av[++i]);
		}
		if (ft_strequ(av[i], "-visual"))
			vm->flag.visual = 1;
		i++;
	}
	if (vm->flag.dump && vm->flag.d)
		terminate(USAGE_DUMP);
}

void		in_close_fd_err(int fd, char *err)
{
	close(fd);
	terminate(err);
}

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
//	if(!(champion->name = ft_strnew(PROG_NAME_LENGTH)))
//		terminate(ERR_MALC_INIT);
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
	if (r != 4 || pl_bytecode_to_int32(buff, 4))
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

	r = read(fd, &buff, 4);
	if (r != 4 ||
	(!(resul = pl_bytecode_to_int32(buff, 4))) ||
	resul != COREWAR_EXEC_MAGIC)
		in_close_fd_err(fd, ERR_BAD_MAGIC);
}

void		pl_cp_comment_champion(int fd, t_list *player)
{
	uint8_t buff[COMMENT_LENGTH];
	int r;

	r = read(fd, &buff, COMMENT_LENGTH);
	if (r == COMMENT_LENGTH)
		ft_memcpy(((t_player*)player->content)->name, buff, PROG_NAME_LENGTH);
	else
		in_close_fd_err(fd, ERR_BAD_COMM);
}

void		pl_cp_name_champion(int fd, t_list *player)
{
	uint8_t buff[PROG_NAME_LENGTH];
	int r;

	r = read(fd, &buff, PROG_NAME_LENGTH);
	if (r == PROG_NAME_LENGTH)
		ft_memcpy(((t_player*)player->content)->name, buff, PROG_NAME_LENGTH);
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
		ft_memcpy(((t_player*)player->content)->exec_code, buff,
			PROG_NAME_LENGTH);
		if (read(fd, &buff, 1) && r)
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

int			ft_compare_end(const char* str, const char* dest, int pos)
{
	int i;

	i = 0;
	if (pos < 0)
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
		i = i + 2;
	else if (ft_strequ(av[i], "-visual"))
		i++;
	return (i);
}

t_list		*pl_list_champions(int ac, int *i, char **av, t_list *champions)
{
	t_list *player;
	int 	num_pl;

	player = NULL;
	num_pl = 0;
	while (!(ft_strstr(av[*i], ".cor")) && *i < ac)
	{
		if (ft_strequ(av[*i], "-n") || ft_strequ(av[*i], "-d") || ft_strequ
		(av[*i], "-dump") || ft_strequ(av[*i], "-visual"))
			//todo: проверить местоположение флагов
		{
			if (ft_strequ(av[*i], "-n"))
			{
				*i = *i + 1;
				if (!av[*i + 1] || (!(num_pl = ft_atoi(av[*i])) && av[*i, 0] >=
				'0' &&
				av[*i, 0] <= '9') || !(ft_compare_end(av[*i + 1],
				".cor\0", ft_strlen(av[*i + 1]) - 4)))
					terminate(ERR_NUM_CHAMP);
				*i = *i + 1;
			}
			*i = pl_next_arg(av, *i, ac);
		}
		else
			terminate(ERR_BAD_NAME);
	}
	if (!ft_compare_end(av[*i], ".cor\0", ft_strlen(av[*i]) - 4))
		terminate(ERR_BAD_NAME);
	player = pl_new_champ(num_pl);
	pl_read_data_champion(av[*i], player);
	*i = *i + 1;
	if(!champions)
		champions = player;
	else
		ft_lstadd(&champions, player);
	return (champions);
}

int			pl_search_duplicate_num(t_list *champions, int quant)
{
	t_list *tmp;

	tmp = champions;
	while (tmp)
	{
		if (((t_player*)tmp->content)->number == quant && quant > 0)
			quant = pl_search_duplicate_num(champions, --quant);
		tmp = tmp->next;
	}
	return (quant);
}

void		pl_check_duplicate_num(t_list *champions)
{
	t_list *tmp;
	t_list *this;

	this = champions;
	while (this->next)
	{
		tmp = this->next;
		while (tmp)
		{
			if (((t_player *) this->content)->number
				== ((t_player *) tmp->content)->number
				|| ((t_player *) this->content)->number > MAX_PLAYERS
				|| ((t_player *) tmp->content)->number > MAX_PLAYERS)
				terminate(ERR_NUM_CHAMP);
			tmp = tmp->next;
		}
		this = this->next;
	}
}

void		pl_number_order(t_list *champions, int quant)
{
	t_list *tmp;

	tmp = champions;
	while (tmp)
	{
		quant = pl_search_duplicate_num(champions, quant);
		if (((t_player*)tmp->content)->number == 0)
			((t_player*)tmp->content)->number = quant--;
		tmp = tmp->next;
	}
	pl_check_duplicate_num(champions);
}

t_list 		*pl_swap(t_list *start, t_list *champ, t_list *tmp, t_list *prev)
{
	if (prev == champ)
	{
		champ->next = tmp->next;
		tmp->next = champ;
		champ = tmp;
		start = champ;
	}
	else
	{
		champ->next = tmp->next;
		tmp->next = champ;
		prev->next = tmp;
	}
	return (start);
}

t_list		*pl_sort_stack_champ(t_list *champions)
{
	t_list *start;
	t_list *prev;
	t_list *tmp;

	prev = champions;
	start = champions;
	while (champions->next)
	{
		tmp = champions->next;
		if (((t_player *) champions->content)->number < ((t_player *)
		tmp->content)->number)
		{
			if (prev == champions)
				start = pl_swap(start, champions, tmp, prev);
			else
				start = pl_swap(start, champions, tmp, prev);
			champions = start;
		}
		else
		{
			prev = champions;
			champions = champions->next;
		}
	}
	return (start);
}

void		pl_check_num_champion(t_list *champions)
{
	int	max_num_player;
	t_list		*tmp;

	if (!champions)
		terminate(ERR_FEW_CHAMP);
	tmp = champions;
	max_num_player = (int)((t_player*)champions->content)->number;
	while (tmp)
	{
		if ((int)((t_player*)tmp->content)->number == max_num_player)
		{
			tmp = tmp->next;
			max_num_player--;
		}
		else
			terminate(ERR_NUM_CHAMP);
	}
}

void		pl_players_order(t_list **champions)
{
	t_list *tmp;
	int quant;

	quant = 0;
	tmp = *champions;
	while (tmp)
	{
		tmp = tmp->next;
		quant++;
	}
	if (quant > MAX_PLAYERS)
		terminate(ERR_MANY_CHAMP);
	pl_number_order(*champions, quant);
	*champions = pl_sort_stack_champ(*champions);
	pl_check_num_champion(*champions);
}

void 	print_num_players(t_list *champ)
{
	t_list *cham;
	int num;

	cham = champ;
	while (cham)
	{
		num = ((t_player*)cham->content)->number;
		ft_printf("_____________________________\nNUM "
			"CHAMP:\t%i\nNAME:\t\t%s\nCOMMENT:\t\t%s\nSI"
			"ZE_CODE:\t%i\nEXEC_CODE:\t%s\n-----------------------------\n\n",
			num, ((t_player*)cham->content)->name,
				((t_player*)cham->content)->comment,
				  ((t_player*)cham->content)->exec_size,
				  ((t_player*)cham->content)->exec_code);
		cham = cham->next;
	}
	ft_printf("\n\n");
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
		champions = pl_list_champions(ac, &i, av, champions);
	}

//	print_num_players(champions);
	pl_players_order(&champions);
//	print_num_players(champions); //todo output data champions;
	return (champions);
}