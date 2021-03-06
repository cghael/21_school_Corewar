/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_add_data_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:41:08 by ablane            #+#    #+#             */
/*   Updated: 2021/02/05 21:07:46 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

void		pl_cp_comment_champion(int fd, t_list *player)
{
	int		r;
	uint8_t	buff[COMMENT_LENGTH];

	r = read(fd, &buff, COMMENT_LENGTH);
	if (pl_check_name_comm(buff, COMMENT_LENGTH) == 0)
		terminate(ERR_BAD_COMM);
	if (r == COMMENT_LENGTH)
		ft_memcpy(((t_player*)player->content)->comment, buff, COMMENT_LENGTH);
	else
		in_close_fd_err(fd, ERR_BAD_COMM);
}

void		pl_cp_name_champion(int fd, t_list *player)
{
	int		r;
	uint8_t	buff[PROG_NAME_LENGTH];

	r = read(fd, &buff, PROG_NAME_LENGTH);
	if (pl_check_name_comm(buff, PROG_NAME_LENGTH) == 0)
		terminate(ERR_BAD_NAME);
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
	if (((t_player*)player->content)->exec_size < 1)
		terminate(ERR_NO_CODE);
	if (((t_player*)player->content)->exec_size > CHAMP_MAX_SIZE)
		terminate(ERR_TO_BIGG);
}

void		pl_cp_code_champion(int fd, t_list *player)
{
	uint32_t	r;
	uint8_t		buff[CHAMP_MAX_SIZE];

	if (((t_player*)player->content)->exec_size > CHAMP_MAX_SIZE)
		terminate(ERR_TO_BIGG);
	r = read(fd, &buff, ((t_player*)player->content)->exec_size);
	if (r == ((t_player*)player->content)->exec_size)
	{
		ft_memcpy(((t_player*)player->content)->exec_code, buff,
			((t_player*)player->content)->exec_size);
		if (read(fd, &buff, 1) && r)
			in_close_fd_err(fd, ERR_BAD_LEN);
	}
	else
		in_close_fd_err(fd, ERR_TO_BIGG);
}
