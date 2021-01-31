/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:15:01 by cghael            #+#    #+#             */
/*   Updated: 2021/01/30 18:15:03 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OP_H
# define ASM_OP_H

# include "op.h"

# include "corewar.h"

# define REG			1
# define DIR			2
# define IND			4
# define REG_DIR		3
# define REG_IND		5
# define DIR_IND		6
# define REG_DIR_IND	7
# define COMMANDS_NUM	16

typedef	enum
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
}	t_typo;

typedef	enum
{
	false,
	true
}	t_bool;

/*
** Operator
*/

/*
** name          — name of operator
** code          — code of operator
** n_args        — number of arguments
** is_args_type  — does bytecode of statement with this operator contain code
**                 of argument's types
** args_types    — types of arguments
** t_dir_size    — size of T_DIR argument
** change_carry  — change carry parameter
** cycles        — number of wait cycles
** fun           — function pointer
*/

typedef struct			s_op
{
	char				*name;
	uint8_t				code;
	int					n_args;
	int					args[3];
	int					is_args_type;
	int					is_small_dir;
	uint8_t				t_dir_size;
	int					change_carry;
	unsigned int		cycles;
	void				(*fun)(t_carriage *car, t_vm *vm);
}						t_op;

static t_op				g_ops[COMMANDS_NUM] = {
	{
		.name = "live",
		.code = 0x01,
		.n_args = 1,
		.args = {DIR, 0, 0},
		.is_args_type = FALSE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = FALSE,
		.cycles = 10,
		.fun = live
	},
	{
		.name = "ld",
		.code = 0x02,
		.n_args = 2,
		.args = {DIR_IND, REG, 0},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = TRUE,
		.cycles = 5,
		.fun = ld
	},
	{
		.name = "st",
		.code = 0x03,
		.n_args = 2,
		.args = {REG, REG_IND, 0},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = FALSE,
		.cycles = 5,
		.fun = st
	},
	{
		.name = "add",
		.code = 0x04,
		.n_args = 3,
		.args = {REG, REG, REG},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = TRUE,
		.cycles = 10,
		.fun = add
	},
	{
		.name = "sub",
		.code = 0x05,
		.n_args = 3,
		.args = {REG, REG, REG},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = TRUE,
		.cycles = 10,
		.fun = sub
	},
	{
		.name = "and",
		.code = 0x06,
		.n_args = 3,
		.args = {REG_DIR_IND, REG_DIR_IND, REG},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = TRUE,
		.cycles = 6,
		.fun = and
	},
	{
		.name = "or",
		.code = 0x07,
		.n_args = 3,
		.args = {REG_DIR_IND, REG_DIR_IND, REG},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = TRUE,
		.cycles = 6,
		.fun = or
	},
	{
		.name = "xor",
		.code = 0x08,
		.n_args = 3,
		.args = {REG_DIR_IND, REG_DIR_IND, REG},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = TRUE,
		.cycles = 6,
		.fun = xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.n_args = 1,
		.args = {DIR, 0, 0},
		.is_args_type = FALSE,
		.is_small_dir = TRUE,
		.t_dir_size = DIR_SIZE / 2,
		.change_carry = FALSE,
		.cycles = 20,
		.fun = zjmp
	},
	{
		.name = "ldi",
		.code = 0x0a,
		.n_args = 3,
		.args = {REG_DIR_IND, REG_DIR, REG},
		.is_args_type = TRUE,
		.is_small_dir = TRUE,
		.t_dir_size = DIR_SIZE / 2,
		.change_carry = FALSE,
		.cycles = 25,
		.fun = ldi
	},
	{
		.name = "sti",
		.code = 0x0b,
		.n_args = 3,
		.args = {REG, REG_DIR_IND, REG_DIR},
		.is_args_type = TRUE,
		.is_small_dir = TRUE,
		.t_dir_size = DIR_SIZE / 2,
		.change_carry = FALSE,
		.cycles = 25,
		.fun = sti
	},
	{
		.name = "fork",
		.code = 0x0c,
		.n_args = 1,
		.args = {DIR, 0, 0},
		.is_args_type = FALSE,
		.is_small_dir = TRUE,
		.t_dir_size = DIR_SIZE / 2,
		.change_carry = FALSE,
		.cycles = 800,
		.fun = lfork
	},
	{
		.name = "lld",
		.code = 0x0d,
		.n_args = 2,
		.args = {DIR_IND, REG, 0},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = TRUE,
		.cycles = 10,
		.fun = ld
	},
	{
		.name = "lldi",
		.code = 0x0e,
		.n_args = 3,
		.args = {REG_DIR_IND, REG_DIR, REG},
		.is_args_type = TRUE,
		.is_small_dir = TRUE,
		.t_dir_size = DIR_SIZE / 2,
		.change_carry = TRUE,
		.cycles = 50,
		.fun = ldi
	},
	{
		.name = "lfork",
		.code = 0x0f,
		.n_args = 1,
		.args = {DIR, 0, 0},
		.is_args_type = FALSE,
		.is_small_dir = TRUE,
		.t_dir_size = DIR_SIZE / 2,
		.change_carry = FALSE,
		.cycles = 1000,
		.fun = lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.n_args = 1,
		.args = {REG, 0, 0},
		.is_args_type = TRUE,
		.is_small_dir = FALSE,
		.t_dir_size = DIR_SIZE,
		.change_carry = FALSE,
		.cycles = 2,
		.fun = aff
	}
};
#endif
