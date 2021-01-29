/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:47:23 by ablane            #+#    #+#             */
/*   Updated: 2021/01/29 14:42:07 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include "errors.h"
# include <fcntl.h>

/*
** struct's definitions
*/

typedef struct				s_flag
{
	uint32_t				visual;
	uint32_t				dump;
	uint32_t				d;
	uint32_t				a;
}							t_flag;

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
	uint8_t					reg_nb;
	uint8_t					type;
	int32_t					pos;
	t_data					data;
	uint32_t				len;
}							t_argument;

typedef struct				s_carriage
{
	uint32_t				number;
	uint8_t					carry;
	uint8_t					operation;
	uint32_t				number_last_live;
	uint32_t				waiting_moves;
	int32_t					position;
	uint8_t					reg[REG_NUMBER][REG_SIZE];
	t_argument				args[3];
	uint8_t					args_len;
	t_player				*player;
}							t_carriage;

typedef struct				s_vm
{
	uint8_t					arena[MEM_SIZE];
	t_player				*last_live_player;
	uint32_t				number_cycle;
	uint32_t				number_live;
	int32_t					cycles_to_die;
	uint32_t				number_checks;
	uint32_t				number_players;
	uint32_t				number_carriages;
	t_list					*carriages;
	t_list					*players;
	t_flag					flag;
}							t_vm;

t_player					*vm_operation(t_vm *vm);
t_vm						*vm_init(int ac, char **av);
t_list						*pl_init_players(int ac, char **av);
uint32_t					len_args(t_carriage *car, t_vm *vm);
t_list						*pl_sort_stack_champ(t_list *champions);
t_carriage  				*cr_init(t_player *player, uint32_t nb);
uint8_t						find_len_arg(uint8_t arg, uint8_t is_small_dir);
int32_t						pl_bytecode_to_int32(const uint8_t *buff, int len);
t_data						get_t_data(uint8_t *array, int32_t pos,
					   		uint32_t max);

//t_list						*vm_init_players(int ac, char **av); todo dell
t_list						*pl_sort_rev_stack_champ(t_list *champions);

//void 						print_players(t_list *champ); todo non function
//void						vm_print_operation(t_carriage *car, t_vm *vm);

int							ft_compare_end(const char *str, const char *dest,
						 	int pos);
int							fl_check_num_after_flag_n(char **av, int i, int ac,
							int *num_pl);
int							pl_search_duplicate_num(t_list *champions,
							uint32_t quantity);
int							pl_next_arg(char **av, int i, t_list *champions);

void                    	terminate(char *s);
void						vm_print_arena(t_vm *vm);
void						pl_check_magic_header(int fd);
void						pl_print_players(t_list *players);
void						print_result(t_player *win_player);
void						in_close_fd_err(int fd, char *err);
void						pl_check_null_champ(int fd, int i);
void						pl_cp_exec_size(int fd, t_list *player);
void						pl_check_num_champion(t_list *champions);
void						pl_check_duplicate_num(t_list *champions);
void						fl_check_flags(int ac, char** av, t_vm *vm);
void						pl_cp_name_champion(int fd, t_list *player);
void						pl_cp_code_champion(int fd, t_list *player);
void						pl_number_order(t_list *champions, int quant);
void						pl_cp_comment_champion(int fd, t_list *player);
void 						set_array(t_data dest, const t_data source,
							uint32_t n);
/*
**  commands
*/

void						ld(t_carriage *car, t_vm *vm);
void						st(t_carriage *car, t_vm *vm);
void						or(t_carriage *car, t_vm *vm);
void						add(t_carriage *car, t_vm *vm);
void						sub(t_carriage *car, t_vm *vm);
void						and(t_carriage *car, t_vm *vm);
void						xor(t_carriage *car, t_vm *vm);
void						ldi(t_carriage *car, t_vm *vm);
void						sti(t_carriage *car, t_vm *vm);
void						aff(t_carriage *car, t_vm *vm);
void						zjmp(t_carriage *car, t_vm *vm);
void						live(t_carriage *car, t_vm *vm);
void						lfork(t_carriage *car, t_vm *vm);

/*
**  newlibft functions
*/

u_int32_t	ft_lstlength(t_list *lst);
t_list		*ft_lstpnew(void *content);
void		ft_lstpdelone(t_list **alst, t_list *del);
int32_t		ft_bytetoint(const t_data arg, uint8_t len);
void		ft_inttobyte(const int32_t num, t_data arg, uint8_t len);

#endif
