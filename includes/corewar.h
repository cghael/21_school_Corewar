/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:11:23 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/19 17:40:30 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

/*
** struct's definitions
*/

typedef struct				s_player
{
	uint32_t				number;
	uint8_t					name[PROG_NAME_LENGTH];
	uint8_t					comment[COMMENT_LENGTH];
	uint8_t					exec_size;
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

void                    	terminate(char *s);
t_vm						*vm_init(int ac, char **av);
t_player					*vm_operation(t_vm *vm);
void						print_result(t_player *win_player);
t_list						*vm_init_players(int ac, char **av);

#endif
