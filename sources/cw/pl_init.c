/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:55:51 by ablane            #+#    #+#             */
/*   Updated: 2020/12/07 14:03:27 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "asm.h"

void		fl_check_flags(int ac, char **av, t_vm *vm)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-dump"))
		{
			i++;
			if (ft_atoi(av[i]) < 1)
				terminate(USAGE_DUMP);
			vm->flag.dump = ft_atoi(av[i++]);
		}
		if (ft_strequ(av[i], "-d"))
		{
			i++;
			if (ft_atoi(av[i]) < 1)
				terminate(USAGE_DUMP);
			vm->flag.d = ft_atoi(av[i++]);
		}
		if (ft_strequ(av[i], "-v"))
			vm->flag.visual = 1;
		i++;
	}
	if (vm->flag.dump && vm->flag.d)
		terminate(USAGE_DUMP);
}

t_list		*pl_new_champ(int num_player)
{
	t_list		*player;
	t_player	*champion;

	champion = NULL;
	player = NULL;
	if (!(player = ft_lstnew(NULL, 0)))
		return (NULL);
	if (!(champion = (t_player*)malloc(sizeof(t_player))))
		return (NULL);
	champion->number = num_player;
	champion->exec_size = 0;
	player->content = champion;
	return (player);
}

int32_t		pl_bytecode_to_int32(const uint8_t *buff, int len)
{
	int		k;
	int		sign;
	int32_t	res;

	k = 0;
	res = 0;
	sign = (buff[0] & 0x80);
	while (len)
	{
		if (sign)
			res += (buff[len - 1] ^ 0xFF << (8 * k++));
		else
			res += (buff[len - 1] << (8 * k++));
		len--;
	}
	if (sign)
		res = ~(res);
	return (res);
}

void		pl_check_null_champ(int fd, int i)
{
	int		r;
	uint8_t	buff[4];

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
	int		r;
	int32_t	resul;
	uint8_t	buff[COMMENT_LENGTH];

	r = read(fd, &buff, MAGIC_LEN);
	if (r != MAGIC_LEN ||
	(!(resul = pl_bytecode_to_int32(buff, MAGIC_LEN))) ||
	resul != COREWAR_EXEC_MAGIC)
		in_close_fd_err(fd, ERR_BAD_MAGIC);
}

void		pl_cp_comment_champion(int fd, t_list *player)
{
	int		r;
	uint8_t	buff[COMMENT_LENGTH];

	r = read(fd, &buff, COMMENT_LENGTH);
	if (r == COMMENT_LENGTH)
		ft_memcpy(((t_player*)player->content)->comment, buff, PROG_NAME_LENGTH);
	else
		in_close_fd_err(fd, ERR_BAD_COMM);
}

void		pl_cp_name_champion(int fd, t_list *player)
{
	int		r;
	uint8_t	buff[PROG_NAME_LENGTH];

	r = read(fd, &buff, PROG_NAME_LENGTH);
	if (r == PROG_NAME_LENGTH)
		ft_memcpy(((t_player*)player->content)->name, buff, PROG_NAME_LENGTH);
	else
		in_close_fd_err(fd, ERR_BAD_NAME);
}

void		pl_cp_exec_size(int fd, t_list *player)
{
	int		r;
	int32_t	res;
	uint8_t	buff[4];

	r = read(fd, &buff, 4);
	if (r != 4)
		in_close_fd_err(fd, ERR_BAD_READ);
	res = pl_bytecode_to_int32(buff, 4);
	((t_player*)player->content)->exec_size = (unsigned int)res;
}

void		pl_cp_code_champion(int fd, t_list *player)
{
	int		r;
	uint8_t	buff[((t_player*)player->content)->exec_size];

	if (((t_player*)player->content)->exec_size > CHAMP_MAX_SIZE)
		terminate(ERR_CODE_LEN);
	r = read(fd, &buff, ((t_player*)player->content)->exec_size);
	if (r == ((t_player*)player->content)->exec_size)
	{
		ft_bzero(((t_player*)player->content)->exec_code, CHAMP_MAX_SIZE);
		ft_memcpy(((t_player*)player->content)->exec_code, buff,
				  ((t_player*)player->content)->exec_size);
		if (read(fd, &buff, 1) && r)
			in_close_fd_err(fd, ERR_BAD_LEN);
	}
	else
		in_close_fd_err(fd, ERR_CODE_LEN);
}

void		pl_read_data_champion(char *file_name, t_list *player)
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

int			ft_compare_end(const char *str, const char *dest, int pos)
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

int			pl_next_arg(char **av, int i)
{
	if (ft_strequ(av[i], "-d") || ft_strequ(av[i], "-dump"))
		i = i + 2;
	else if (ft_strequ(av[i], "-v"))
		i++;
	return (i);
}

int			fl_check_num_after_flag(char **av, int i, int *num_pl, int ac)
{
	size_t	len;

	if (i + 1 < ac)
		len = ft_strlen(av[i + 1]) - 4;
	else
		return (1);
	if (ft_strequ(av[i], "-n"))
	{
		i++;
		if (i < ac && av[i][0] >= '0' && av[i][0] <= '9')
		{
			*num_pl = ft_atoi(av[i]);
			if (!(ft_compare_end(av[i + 1], ".cor\0", len)) && *num_pl < 1)
				terminate(ERR_NUM_CHAMP);
		}
		else
			terminate(ERR_NUM_CHAMP);
		i++;
	}
	return (pl_next_arg(av, i));
}

void		pl_free_champions(t_list *champions, char *err)
{
	t_list *tmp;

	while (champions)
	{
		tmp = champions;
		champions = champions->next;
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = NULL;
	}
	if (err)
		terminate(err);
}

t_list		*pl_list_champions(int ac, int *i, char **av, t_list *champions)
{
	int		num_pl;
	t_list	*player;

	player = NULL;
	num_pl = 0;
	while (!(ft_strstr(av[*i], ".cor")) && *i < ac)
	{
		if (ft_strequ(av[*i], "-n") || ft_strequ(av[*i], "-d") ||
		ft_strequ(av[*i], "-dump") || ft_strequ(av[*i], "-v"))
			*i = fl_check_num_after_flag(av, *i, &num_pl, ac);
		else
			terminate(ERR_BAD_NAME);
	}
	if (!ft_compare_end(av[*i], ".cor\0", ft_strlen(av[*i]) - 4))
		terminate(ERR_BAD_NAME);
	if(!(player = pl_new_champ(num_pl)))
		pl_free_champions(champions, ERR_MALC_INIT);
	pl_read_data_champion(av[*i], player);
	*i = *i + 1;
	if (!champions)
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
			if (((t_player*)this->content)->number
				== ((t_player*)tmp->content)->number
				|| ((t_player*)this->content)->number > MAX_PLAYERS
				|| ((t_player*)tmp->content)->number > MAX_PLAYERS)
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

t_list		*pl_swap(t_list *start, t_list *champ, t_list *tmp, t_list *prev)
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
		if (((t_player*)champions->content)->number < ((t_player *)
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
	int			max_num_player;
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

t_list		*pl_players_order(t_list *champions)
{
	int		quant;
	t_list	*tmp;

	quant = 0;
	tmp = champions;
	while (tmp)
	{
		tmp = tmp->next;
		quant++;
	}
	if (quant > MAX_PLAYERS)
		terminate(ERR_MANY_CHAMP);
	pl_number_order(champions, quant);
	champions = pl_sort_stack_champ(champions);
	pl_check_num_champion(champions);
	return (champions);
}

t_list		*pl_sort_rev_stack_champ(t_list *champions)
{
	t_list *start;
	t_list *prev;
	t_list *tmp;

	prev = champions;
	start = champions;
	while (champions->next)
	{
		tmp = champions->next;
		if (((t_player*)champions->content)->number > ((t_player *)
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

void		print_players(t_list *champ)
{
	t_list	*cham;

	cham = pl_sort_rev_stack_champ(champ);
	ft_printf("Introducing contestants...\n");
	while (cham)
	{
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\")\n",
			((t_player*)cham->content)->number,
			((t_player*)cham->content)->exec_size,
			((t_player*)cham->content)->name,
			((t_player*)cham->content)->comment);
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
		terminate(USAGE); //todo describe USAGE;
	while (i < ac)
		champions = pl_list_champions(ac, &i, av, champions);
	return (pl_players_order(champions));
}

