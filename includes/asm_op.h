//
// Created by Cora Ghael on 11/23/20.
//

#ifndef ASM_OP_H
# define ASM_OP_H

//# include "op.h"
//# include "libft.h"

# define REG			1
# define DIR			2
# define IND			4
# define REG_DIR		3
# define REG_IND		5
# define DIR_IND		6
# define REG_DIR_IND	7

typedef					enum
{
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
}						t_typo;

typedef struct			s_op
{
	char				*name;
	int					code;
	int					n_args;
	int					args[3];
	int					is_args_type;
	int					is_small_dir;
}						t_op;

static t_op				g_ops[16] = {
		{
			.name = "live",
			.code = 0x01,
			.n_args = 1,
			.args = {DIR, 0, 0},
			.is_args_type = FALSE,
			.is_small_dir = FALSE
		},
		{
			.name = "ld",
			.code = 0x02,
			.n_args = 2,
			.args = {DIR_IND, REG, 0},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		},
		{
			.name = "st",
			.code = 0x03,
			.n_args = 2,
			.args = {REG, REG_IND, 0},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		},
		{
			.name = "add",
			.code = 0x04,
			.n_args = 3,
			.args = {REG, REG, REG},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		},
		{
			.name = "sub",
			.code = 0x05,
			.n_args = 3,
			.args = {REG, REG, REG},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		},
		{
			.name = "and",
			.code = 0x06,
			.n_args = 3,
			.args = {REG_DIR_IND, REG_DIR_IND, REG},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		},
		{
			.name = "or",
			.code = 0x07,
			.n_args = 3,
			.args = {REG_DIR_IND, REG_DIR_IND, REG},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		},
		{
			.name = "xor",
			.code = 0x08,
			.n_args = 3,
			.args = {REG_DIR_IND, REG_DIR_IND, REG},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		},
		{
			.name = "zjmp",
			.code = 0x09,
			.n_args = 1,
			.args = {DIR, 0, 0},
			.is_args_type = FALSE,
			.is_small_dir = TRUE
		},
		{
			.name = "ldi",
			.code = 0x0a,
			.n_args = 3,
			.args = {REG_DIR_IND, REG_DIR, REG},
			.is_args_type = TRUE,
			.is_small_dir = TRUE
		},
		{
			.name = "sti",
			.code = 0x0b,
			.n_args = 3,
			.args = {REG, REG_DIR_IND, REG_DIR},
			.is_args_type = TRUE,
			.is_small_dir = TRUE
		},
		{
			.name = "fork",
			.code = 0x0c,
			.n_args = 1,
			.args = {DIR, 0, 0},
			.is_args_type = FALSE,
			.is_small_dir = TRUE
		},
		{
			.name = "lld",
			.code = 0x0d,
			.n_args = 2,
			.args = {DIR_IND, REG, 0},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		},
		{
			.name = "lldi",
			.code = 0x0e,
			.n_args = 3,
			.args = {REG_DIR_IND, REG_DIR, REG},
			.is_args_type = TRUE,
			.is_small_dir = TRUE
		},
		{
			.name = "lfork",
			.code = 0x0f,
			.n_args = 1,
			.args = {DIR, 0, 0},
			.is_args_type = FALSE,
			.is_small_dir = TRUE
		},
		{
			.name = "aff",
			.code = 0x10,
			.n_args = 1,
			.args = {REG, 0, 0},
			.is_args_type = TRUE,
			.is_small_dir = FALSE
		}
};

#endif //ASM_OP_H
