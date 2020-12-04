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
# define IS_NOT_FILE		-1
# define IS_S_FILE			0
# define IS_COR_FILE		1
# define IS_BAD_FILE		2

# define ERR_ASM_STRUCT		"Error in ft_init_asm_struct"
# define ERR_MEMALLOC		"Error in ft_memalloc()"
# define ERR_NAME_LEN		"Champion name too long (Max length 128)" // ?
# define ERR_DOUBLE_NAME	-1
# define ERR_DOUBLE_COMMENT	-2
# define ERR_UNKNOWN_CMD	-3
# define ERR_NO_NAME		-4
# define ERR_DIS			"Error in ft_disassemble()\n"
# define ERR_DIS_FILE		"Error in ft_dis_filename_treat()\n"
# define ERR_DIS_CHOOSE		"Error in ft_dis_choose_new_filename()\n"
# define ERR_DIS_INIT		"Error in ft_dis_init_struct()\n"
# define ERR_OPEN_SOL		"Error in ft_open_solution_file()\n"
# define ERR_DIS_STATEMENT	"Error in ft_dis_init_statement()\n"
# define ERR_READ_FILE		"Error read file\n"
# define ERR_DIS_NO_NULL	"Error in ft_dis_parse_bytecode(): No NULL\n"
# define ERR_DIS_CODE_SIZE	"Error in ft_dis_parse_bytecode(): bad codesize\n"
# define ERR_DIS_MAGIC		"Error in ft_dis_parse_bytecode(): Bad MAGIC_CODE\n"
# define ERR_DIS_FILE_SIZE	"Too small\\wrong .name .comment"

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

# define FILE_EXIST			0
# define FILE_NOT_EXIST		1
# define FILE_EXIST_TXT		"[\e[1;33m%s\e[m] already exist or incorrect\n"
# define FILE_INPUT_NEW		"input new_filename:\n>>>\t"
# define FILE_SAVE_OK		"Ok! I save file to [\e[1;33m%s\e[m]\n"

/*
** ------------------------------ Structures -----------------------------------
*/

typedef						enum
{
	false,
	true
}							t_bool;

typedef struct				s_parse
{
	char					*line;
	int						res;
	int						n_line;
	t_errors				err_num;
	int						endline;
	int						is_whitespace;
}							t_parse;

typedef struct				s_args
{
	uint8_t					type;
	char					*content;
	int						is_label;
}							t_args;

typedef struct				s_operations
{
	t_typo					num;
	unsigned				n_line;
	unsigned				pos;
	uint8_t					args_code;
	t_args					*args;
	struct s_operations		*next;
	struct s_operations		*last;
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


typedef struct				s_statement
{
	t_op					*op;
	uint8_t					args_types[3];
	int32_t					args[3];
	struct s_statement		*next;
}							t_statement;//todo?

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
	t_statement				*statements;//todo?
}							t_dis;

int							ft_disassemble(char *file_cor, t_asm *asm_s);
int							ft_dis_error(char *error_text, void *data_for_free);
t_dis *ft_dis_init_struct(char *file_cor);
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

////-------------------------------- to refactor


int32_t					ft_dis_bytecode_to_int32(const uint8_t *bytecode, \
																size_t size);
int						ft_dis_parse_bytecode(t_dis *dis_s);
void					ft_dis_valide_name(t_dis *dis_s);
void					ft_dis_valide_comment(t_dis *dis_s);
void					ft_dis_process_exec_code(t_dis *dis_s);
void					ft_dis_write_file(t_dis *dis_s);
//todo hmm?
/*t_statement				*ft_dis_init_statement();
void					validate_types_code(t_parser *parser,
											int8_t args_types_code,
											int args_num);
t_bool					is_arg_types_valid(t_statement *statement);
void					name_warning(size_t pos);
void					comment_warning(size_t pos);
void					types_code_warning(size_t pos);
void					process_arg_types(t_parser *parser,
										  t_statement *statement);
void					add_statement(t_statement **list, t_statement *new);
void					free_bytecode_parser(t_parser **parser);

void					op_code_error(t_parser *parser);
void					arg_types_code_error(t_parser *parser);
void					length_error(t_parser *parser);
void					register_error(t_parser *parser);*/

/////////---------------------------------- end refactor

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
int							ft_check_n_write_op_args(t_asm *asm_s);
int							ft_get_one_arg(t_asm *asm_s, int arg_pars);
int							ft_count_num_len(const char *str);
int							ft_check_arg_type(t_asm *asm_s, int type, int arg_pars);
void						ft_write_arg_type_code(t_asm *asm_s);
void						ft_count_exec_code_size(t_asm *asm_s);
int							ft_write_exec_code_in_line(t_asm *asm_s);

#endif
