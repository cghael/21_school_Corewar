/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:49:00 by ablane            #+#    #+#             */
/*   Updated: 2020/11/30 12:24:21 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "errors.h"
# include "op.h"
# include <fcntl.h>
# include "asm.h"
# include "stdbool.h"

typedef struct				s_player
{
	int						number;
	char					*name[PROG_NAME_LENGTH];
	char					*comment[COMMENT_LENGTH];
	unsigned int			exec_size;
	unsigned char			exec_code[CHAMP_MAX_SIZE];
}							t_player;

typedef struct				s_carriage
{
	unsigned int			number;
	unsigned short int		carry;
	unsigned char			operation;
	unsigned int			number_last_live;
	unsigned int			waiting_moves;
	unsigned int			position;
	unsigned char			reg[REG_NUMBER];
	t_player				*player;
}							t_carriage;

typedef struct				s_vm
{
	unsigned char			arena[MEM_SIZE];
	t_player				*last_live_player;
	unsigned int			number_cycle;
	unsigned int			number_live; //number of live transactions for the period
	int						cycles_to_die;
	unsigned int			number_checks;
	t_list					*carriages;
	t_list					*players;
}							t_vm;

t_vm						*vm_init(int ac, char **av);
t_player					*vm_operation(t_vm *vm);
void						in_close_fd_err(int fd, char *err);
void						print_result(t_player *win_player);
void						terminate(char *s);
t_list						*pl_parsing_input(int ac, char **av);
t_player					*pl_max_number(t_list *players);
void						pl_check_magic_header(int fd);

#endif
