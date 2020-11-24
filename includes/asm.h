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
# include "errors.h"
# include "asm_op.h"

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
# define ERR_ASM_STRUCT		"error in ft_init_asm_struct"
# define ERR_MEMALLOC		"ERROR in ft_memalloc()"
# define IS_NOT_FILE		-1
# define IS_S_FILE			0
# define IS_COR_FILE		1
# define IS_BAD_FILE		2

# define ERR_WRITE_BYTE		"Error in ft_write_bytecode_to_file()\n"
# define ERR_NAME_LEN		"Champion name too long (Max length 128)"
# define ERR_DOUBLE_NAME	-1
# define ERR_DOUBLE_COMMENT	-2
# define ERR_UNKNOWN_CMD	-3
# define ERR_NO_NAME		-4
# define ERR_DIS_FILE		"Error in ft_dis_filename_treat()\n"
# define ERR_DIS_CHOOSE		"Error in ft_dis_choose_new_filename()\n"
# define ERR_DIS_INIT		"Error in ft_dis_init_struct()\n"

# define NAME_START			1
# define NAME_END			2
# define CMT_START			3
# define CMT_END			4
# define NAME_CMT_FOUND		5

# define OK_WRITE_BYTE		0
# define MAGIC_LEN			4
# define END_SIZE			4
# define EXEC_SIZE			END_SIZE
# define PARSING_ERR		-1
# define PARSING_OK			0

# define IS_NAME			2
# define IS_COMMENT			3
# define IS_NOT_COMMAND		-1

# define FILE_EXIST			"[%s] already exist\ninput new_filename:\n>>>\t"
# define WRONG_SCANF_INPUT	"Wrong input\nnew_filename is [%s.s]\n"
# define _IS_CORRECT		"it's correct? (Y/n)\n"
# define Q_CORRECT_NAME		"new_filename is [%s.s]\nit's correct? (Y/n)\n"
/*
** ------------------------------ Structures -----------------------------------
*/

typedef struct				s_parse
{
	char					*line;
	int						res;
	int						n_line;
	t_errors				err_num;
	int						endline;
	int						is_whitespace;
}							t_parse;

typedef struct				s_operations
{
	t_typo					num;
	unsigned				n_line;
	unsigned				pos;
	struct s_operations		*next;
}							t_operations;

typedef struct				s_mention
{
	unsigned				n_line;
	unsigned				pos;
	int32_t					op_pos;
	size_t					size;
	struct s_mention		*next;
}							t_mention;

typedef struct				s_label
{
	const char				*name;
	int						n_line;
	int32_t					byte_pos;
	struct s_mention		*mention;
	struct s_label			*next;
	struct s_label			*last;
}							t_label;

typedef struct				s_asm
{
	int						fd;
	int						fd_solution;
	t_parse					*parse;
	int						quotes;
//	int						n_lines;
//	unsigned				line;
//	unsigned				column;
//	t_token					*tokens;
	t_operations			*ops;
	int32_t					exec_size;
	int32_t					pos;
	char					*name;
	char					*comment;
	char					*code;
	int32_t					code_size;
	t_label					*labels;
}							t_asm;

/*
** ----------------------------- Disassembler ----------------------------------
*/

typedef struct				s_dis
{
	int						fd_cor;
	char					*new_filename;
}							t_dis;

int							ft_disassemble(char *file_cor, t_asm *asm_s);
int							ft_dis_error(char *error_text, void *data_for_free);
t_dis						*ft_dis_init_struct(void);
void						ft_dis_correct_input(char *answer, \
											char *file_disassemble, \
											char *new_filename, t_dis *dis_s);
void						ft_dis_choose_new_filename(char *file_disassemble, \
											t_dis *dis_s);
int							ft_dis_filename_treat(char *file_cor, t_dis *dis_s);

/*
** ------------------------------ Functions ------------------------------------
*/

t_asm						*ft_init_asm_struct();
void						ft_parse_line(t_asm *asm_s);
void						ft_free_asm_struct(t_asm *asm_s);
int							ft_is_filename(char *filename, t_asm *asm_s);
void						ft_check_read_argv_files(int argc, char **argv);
void						ft_assemble(char *file, t_asm *asm_s);
int							ft_print_help(void);
void						ft_asm_error(char *error_text, t_asm *asm_s);
void						ft_asm_error_in_line(t_asm *asm_s);
void						ft_write_bytecode_to_file(int fd, t_asm *asm_s);
void						ft_int32_to_bytecode(char *data, int32_t pos, \
													int32_t val, size_t size);
void						ft_open_solution_file(char *file, t_asm *asm_s);
int							ft_parse_file(t_asm *asm_s);
int							ft_is_whitespace(char c);
int							ft_line_of_whitespaces_or_comment(t_asm *asm_s);
int							ft_line_data_processing(t_asm *asm_s);
int							ft_start_check_name_or_comment(t_asm *asm_s);
void						ft_print_error(char *error, char *func, int line);
int							ft_check_quotes(t_asm *asm_s);
int							ft_open_quotes_processing(t_asm *asm_s);
char						*ft_strjoin_n_free(char *s1, char *s2);
int							ft_check_operation(t_asm *asm_s);
int							ft_init_n_add_token(t_asm *asm_s, t_typo typo, char *content);
int 						ft_check_end_newline(t_asm *asm_s);
//int							ft_is_label_char(char ch);
//int							ft_is_label_in_line(t_asm *asm_s, const char *colon);
int							ft_label_saving_n_pos_update(t_asm *asm_s, char *colon);
//int							ft_is_mention(t_asm *asm_s, const char *colon, int *pos);
int							ft_operation_processing_n_pos_update(t_asm *asm_s);
int							ft_label_processing_n_pos_update(t_asm *asm_s);
int							ft_is_label_char(char ch);

#endif
