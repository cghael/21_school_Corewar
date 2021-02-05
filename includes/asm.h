/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:11:23 by ksemele           #+#    #+#             */
/*   Updated: 2020/12/07 15:10:45 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ASM_H
# define COREWAR_ASM_H

/*
** --------------------------- External headers --------------------------------
*/

# include <fcntl.h>
# include "libft.h"
# include "errors.h"
# include "asm_op.h"
# include <stdio.h>
# include <errno.h>

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
# define IS_NOT_FILE		-1
# define IS_S_FILE			0
# define IS_COR_FILE		1
# define IS_BAD_FILE		2

# define ERR_ASM_STRUCT		"ERROR: in ft_init_asm_struct"
# define ERR_MEMALLOC		"ERROR: in ft_memalloc()"
# define ERR_DIS_INIT		"ERROR: in ft_dis_init_struct()\n"
# define ERR_DIS_FILE		"ERROR: in ft_dis_filename_treat()\n"
# define ERR_DIS_CHOOSE		"ERROR: in ft_dis_choose_new_filename()\n"
# define ERR_DIS_READ_INPUT	"ERROR: wrong input\n"
# define ERR_DIS_CRT_FILE	"ERROR: can't create file\n"
# define ERR_DIS_OPEN_SOL	"ERROR: in ft_open_solution_file()\n"
# define ERR_DIS_READ_FILE	"ERROR: read file FAIL\n"
# define ERR_DIS_STR_INIT	"ERROR: initialize string FAIL\n"
# define ERR_DIS_ELEM_INIT	"ERROR: initialize element FAIL\n"
# define ERR_DIS_INVLD_FILE	"ERROR: Invalid champion file\n"
# define ERR_DIS_MAGIC		"ERROR: Invalid magic header\n"
# define ERR_DIS_NO_NULL	"ERROR: No NULL control bytes in file\n"
# define ERR_DIS_CODE_INIT	"ERROR: initialize string of code FAIL\n"
# define ERR_DIS_CODE_SIZE	"ERROR: Invalid code size\n"
# define ERR_DIS_CODE_TYPE	"ERROR: Wrong code of arg types at [%u] byte\n"
# define ERR_DIS_OPCODE		"ERROR: Wrong operator code at [%u] byte\n"
# define ERR_DIS_LENGTH		"ERROR: Not enough bytes at [%u] byte\n"
# define ERR_DIS_REGISTER	"ERROR: Wrong register id at [%u] byte\n"

# define WARN_DIS			"WARNING: "
# define WARN_DIS_NAME		"Name ending not NULL bytes: [%zu]\n"
# define WARN_DIS_COMM		"Comment ending not NULL bytes: [%zu]\n"
# define WARN_DIS_CODE_TYP1	"Insignificant bits in code of args types are "
# define WARN_DIS_CODE_TYP2	"not NULL: [%zu]\n"

# define NAME_START			1
# define CMT_START			3
# define NAME_CMT_FOUND		5

# define MAGIC_LEN			4
# define END_SIZE			4
# define EXEC_SIZE			END_SIZE
# define PARSING_ERR		-1
# define PARSING_OK			0
# define OP_CHARS			"abcdefghijklmnopqrstuvwxyz"

# define FILE_EXIST			0
# define FILE_NOT_EXIST		1
# define FILE_EXIST_TXT		"[\e[1;33m%s\e[m] already exist or incorrect\n"
# define FILE_INPUT_NEW		"input new_filename:\n>>>\t"
# define FILE_SAVE_OK		"Ok! I save file to [\e[1;33m%s\e[m]\n"

/*
** ------------------------------ Structures -----------------------------------
*/

typedef struct				s_pos
{
	int						line;
	int						pos;
}							t_pos;

typedef struct				s_parse
{
	char					*line;
	int						res;
	int						n_line;
	t_errors				err_num;
	int						endline;
	int						is_whitespace;
	t_pos					name;
	t_pos					comment;
}							t_parse;

typedef struct				s_args
{
	uint8_t					type;
	char					*content;
}							t_args;

typedef struct				s_operations
{
	t_typo					num;
	unsigned				pos;
	uint8_t					args_code;
	t_args					*args;
	struct s_operations		*next;
	struct s_operations		*last;
}							t_operations;

typedef struct				s_mention
{
	int						n_line;
	t_operations			*op;
	int						arg_num;
	unsigned				pos;
	int32_t					op_pos;
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
	t_operations			*op_list;
	int32_t					pos;
	char					*name;
	char					*comment;
	char					*code;
	int32_t					exec_size;
	t_label					*labels;
}							t_asm;

/*
** ----------------------------- Disassembler ----------------------------------
*/

typedef struct				s_elem
{
	t_op					*op;
	uint8_t					args_types[3];
	int32_t					args[3];
	struct s_elem			*next;
}							t_elem;

typedef struct				s_dis
{
	int						fd_s;
	int						fd_cor;
	char					*file_s;
	char					*name;
	char					*comment;
	int32_t					code_size;
	uint8_t					*code;
	int32_t					pos;
	t_elem					*elems;
	int						corr_name;
}							t_dis;

int							ft_disassemble(char *file_cor);
int							ft_dis_error_free(char *error_text, \
							void *data_for_free, t_dis *dis_s);
t_dis						*ft_dis_init_struct(char *file_cor);
int							ft_dis_free_struct(t_dis *dis_s);
int							ft_dis_choose_new_filename(t_dis *dis_s);
int							ft_dis_check_file_exist(t_dis *dis_s);
int							ft_dis_try_create_file(t_dis *dis_s);
void						ft_dis_ask_new_filename(t_dis *dis_s);
int							ft_dis_copy_filename(char *filename, t_dis *dis_s);
int							ft_dis_add_s(t_dis *dis_s);
int							ft_dis_del_cor(t_dis *dis_s);
int							ft_dis_convert_start_filename(char *file, \
							t_dis *dis_s);
int							ft_dis_read_write(t_dis *dis_s);
void						ft_dis_write_file(t_dis *dis_s);

t_elem						*ft_dis_init_element();
int							ft_dis_parse_bytecode(t_dis *dis_s);
void						ft_dis_validate_name(t_dis *dis_s);
void						ft_dis_validate_comment(t_dis *dis_s);
void						ft_dis_validate_code_types(t_dis *dis_s, \
							int8_t args_types_code, int args_num);
t_bool						ft_dis_is_arg_types_valide(t_elem *elem);
void						ft_dis_warning_name(size_t pos);
void						ft_dis_warning_comment(size_t pos);
void						ft_dis_code_types_warning(size_t pos);
int							ft_dis_treat_exec_code(t_dis *dis_s);
void						ft_dis_treat_arg_types(t_dis *dis_s, \
							t_elem *elem);
void						ft_dis_add_elem(t_elem **list, t_elem *new);
void						*ft_dis_error_opcode(t_dis *dis_s);
void						*ft_dis_error_arg_types_code(t_dis *dis_s);
void						*ft_dis_error_length(t_dis *dis_s);
int							ft_dis_error_register(t_dis *dis_s);
int32_t						ft_dis_bytecode_to_int32(const uint8_t *bytecode, \
							size_t size);
int32_t						ft_dis_parse_int32(int fd);
char						*ft_dis_parse_str(int fd, size_t len);
uint8_t						*ft_dis_parse_code(int fd, size_t len);
t_elem						*ft_dis_args_treat(t_dis *dis_s);
size_t						ft_dis_get_size(t_elem *elem, unsigned int i);
int							ft_dis_treat_arg(t_dis *dis_s, \
							t_elem *elem, unsigned int i);
int							ft_dis_treat_args(t_dis *dis_s, t_elem *elem);
uint8_t						ft_dis_get_arg_type(int8_t code);
void						ft_dis_set_arg_type(int8_t arg_code, int8_t index, \
							t_elem *elem);

/*
** ------------------------------ Assembler ------------------------------------
*/

t_asm						*ft_init_asm_struct();
void						ft_parse_line(t_asm *asm_s);
void						ft_free_asm_struct(t_asm *asm_s);
int							ft_is_filename(char *filename, t_asm *asm_s);
void						ft_check_read_argv_files(int argc, char **argv);
int							ft_assemble(char *file, t_asm *asm_s);
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
int							ft_check_end_newline(t_asm *asm_s);
int							ft_label_saving_n_pos_update(t_asm *asm_s, \
							char *colon);
int							ft_operation_processing_n_pos_update(t_asm *asm_s);
int							ft_label_processing_n_pos_update(t_asm *asm_s, \
							int pos);
int							ft_is_label_char(char ch);
int							ft_check_n_write_op_args(t_asm *asm_s, \
							int args_num);
int							ft_get_one_arg(t_asm *asm_s, int arg_pars);
int							ft_count_num_len(const char *str);
int							ft_check_arg_type(t_asm *asm_s, int type, \
							int arg_pars);
void						ft_write_arg_type_code(t_asm *asm_s);
void						ft_count_exec_code_size(t_asm *asm_s);
int							ft_write_exec_code_in_line(t_asm *asm_s);
void						ft_write_code_to_exec(char *exec, \
							t_operations *tmp);
int							ft_get_label_mention(t_asm *asm_s, int arg_pars, \
							int type);
int							ft_init_n_add_label(t_asm *asm_s, \
							const char *name, int n_line);
t_label						*ft_search_label_exist(t_asm *asm_s, char *name);
int							ft_init_n_add_mention(t_asm *asm_s, int arg_pars, \
							t_label *label);
int							ft_transform_mentions(t_asm *asm_s);
void						ft_asm_error_no_label(t_asm *asm_s);
int							ft_is_op_char(char ch);
int							ft_get_one_line(const int fd, char **line);

#endif
