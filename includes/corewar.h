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
	uint32_t				exec_size;
	uint8_t					exec_code[CHAMP_MAX_SIZE];
}							t_player;

typedef struct				s_data
{
	uint32_t				max;
	int32_t					pos;
	uint8_t					*data;
}							t_data;

typedef struct				s_argument
{
	uint8_t					type;
	int32_t					pos;
	t_data					data;
	uint8_t					len;
}							t_argument;

typedef struct				s_carriage
{
	uint32_t				number;
	uint8_t					carry;
	uint8_t					operation;
	uint32_t				number_last_live;
	uint32_t				waiting_moves;
	uint32_t				position;
	uint8_t					reg[REG_NUMBER][REG_SIZE];
	t_argument				args[3];
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
	uint32_t				number_players;
	t_list					*carriages;
	t_list					*players;
}							t_vm;

void                    	terminate(char *s);
t_vm						*vm_init(int ac, char **av);
t_player					*vm_operation(t_vm *vm);
void						print_result(t_player *win_player);
void						vm_print_arena(t_vm *vm);
t_list						*vm_init_players(int ac, char **av);
uint8_t						find_len_arg(uint8_t arg, uint8_t is_small_dir);
void 						set_array(t_data dest, const t_data source,
					 		uint32_t n);
t_data						get_t_data(uint8_t *array, int32_t pos,
							uint32_t max);

/*
**  commands
*/

void						live(t_carriage *car, t_vm *vm);
void						ld(t_carriage *car, t_vm *vm);
void						st(t_carriage *car, t_vm *vm);
void						zjmp(t_carriage *car, t_vm *vm);
void						sti(t_carriage *car, t_vm *vm);
void						ldi(t_carriage *car, t_vm *vm);

/*
**  newlibft functions
*/

t_list		*ft_lstpnew(void *content);
void		ft_lstpdelone(t_list **alst, t_list *del);
u_int32_t	ft_lstlength(t_list *lst);
int32_t		ft_bytetoint(const t_data arg, uint8_t len);

#endif
