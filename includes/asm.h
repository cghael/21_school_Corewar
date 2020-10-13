/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:11:23 by ksemele           #+#    #+#             */
/*   Updated: 2020/10/11 19:11:27 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ASM_H
# define COREWAR_ASM_H

/*
** --------------------------- External headers --------------------------------
*/

# include <fcntl.h>
# include "libft.h"
# include "op.h"

/*
** ALLOWED funcs:
** open
** read
** lseek
** write
** close
** malloc
** realloc
** free
** perror
** strerror
** exit
*/

/*
** --------------------------- Macros \ Static ---------------------------------
*/

# define STRINGS_EQU		1
# define ASM_STRUCT_ERR		"error in ft_init_asm_struct"
# define MEMALLOC_ERR		"ft_memalloc() error"
# define IS_NOT_FILE		-1
# define IS_S_FILE			0
# define IS_COR_FILE		1
# define IS_BAD_FILE		2
# define ERR_WRITE_BYTE		"Error in ft_write_bytecode_to_file()\n"
# define MAGIC_LEN			4
# define END_SIZE			4
# define EXEC_SIZE			END_SIZE
/*
** ------------------------------ Structures -----------------------------------
*/

typedef struct				s_asm
{
	int						fd;
	unsigned				row;
	unsigned				column;
	t_token					*tokens;
	int32_t					exec_size;
	int32_t					op_pos;
	char					*name;
	char					*comment;
	char					*code;
	int32_t					code_size;
	t_label					*labels;
}							t_asm;

/*
** ------------------------------ Functions ------------------------------------
*/

t_asm						*ft_init_asm_struct();
void						ft_free_asm_struct(t_asm *asm_struct);
int ft_is_filename(char *filename, t_asm *asm_struct);
void ft_check_read_argv_files(int argc, char **argv, t_asm *asm_struct);
void						ft_assemble(char *file, t_asm *asm_struct);
void ft_disassemble(char *file, t_asm *asm_struct);
int							ft_print_help(void);
void						ft_asm_error(char *error_text, t_asm *asm_struct);
void						ft_write_bytecode_to_file(int fd, \
															t_asm *asm_struct);

#endif
