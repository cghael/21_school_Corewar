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
	uint32_t				number;
	uint8_t					name[PROG_NAME_LENGTH];
	uint8_t					comment[COMMENT_LENGTH];
	uint32_t				exec_size;
	uint8_t					exec_code[CHAMP_MAX_SIZE];
}							t_player;

typedef struct				s_carriage
{
	uint32_t				number;
	uint8_t					carry;
	uint8_t					operation;
	uint32_t				number_last_live;
	uint32_t				waiting_moves;
	uint32_t				position;
	uint8_t					reg[REG_NUMBER][REG_SIZE];
	t_player				*player;
}							t_carriage;

typedef struct				s_vm
{
	uint8_t					arena[MEM_SIZE];
	t_player				*last_live_player;
	uint32_t				number_cycle;
	uint32_t				number_live;
	uint32_t				cycles_to_die;
	uint32_t				number_checks;
	t_list					*carriages;
	t_list					*players;
}							t_vm;

t_vm						*vm_init(int ac, char **av);
t_player					*vm_operation(t_vm *vm);
void						in_close_fd_err(int fd, char *err);
void						print_result(t_player *win_player);
void						vm_print_arena(t_vm *vm);
t_list						*vm_init_players(int ac, char **av);
void						terminate(char *s);
t_list						*pl_parsing_input(int ac, char **av);
t_player					*pl_max_number(t_list *players);
void						pl_check_magic_header(int fd);

/*
**  temporary functions
*/

int32_t		ucarrtoint(uint8_t const arg[], uint8_t len);

#endif
