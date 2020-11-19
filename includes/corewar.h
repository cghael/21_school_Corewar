/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:11:23 by ksemele           #+#    #+#             */
/*   Updated: 2020/11/19 17:19:27 by esnowpea         ###   ########.fr       */
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
	int						number;
	char					name[PROG_NAME_LENGTH];
	char					comment[COMMENT_LENGTH];
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
	unsigned int			number_live;
	int						cycles_to_die;
	unsigned int			number_checks;
	t_list					*carriages;
}							t_vm;

t_vm						*vm_init(int ac, char **av);
t_player					*vm_operation(t_vm *vm);
void						print_result(t_player *win_player);

#endif
