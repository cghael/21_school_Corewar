# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksemele <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 14:03:53 by ksemele           #+#    #+#              #
#    Updated: 2020/12/07 14:03:56 by ksemele          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CW = corewar
NAME_ASM = asm

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIR)
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS)

#----------------------------------library--------------------------------------

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

#----------------------------------headers--------------------------------------

HEADERS_LIST = corewar.h \
				asm.h

HEADERS_DIR = includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#----------------------------------sources--------------------------------------

#-----------------------------------Hints---------------------------------------
# Use this trick in terminal to grep all ft_* files in ./src:
#	ls -l | grep 'ft' | awk '{print $9 " \\"}'

SRC_LIST =
SRC_LIST_CW = corewar.c \
                init.c \
                operation.c \
                print.c \
                terminate.c \
                libft.c \
                commands/live.c \
                commands/ld.c \
                commands/sti.c \
                commands/st.c \
                commands/ldi.c \
                commands/zjmp.c \
                commands/add.c \
                commands/sub.c \
                commands/and.c \
                commands/or.c \
                commands/xor.c \
                commands/fork.c \
                commands/aff.c
SRC_LIST_ASM = asm.c \
				ft_asm_error.c \
				ft_assemble.c \
				ft_check_arg_type.c \
				ft_check_end_newline.c \
				ft_check_n_write_op_args.c \
				ft_check_operation.c \
				ft_check_quotes.c \
				ft_check_read_argv_files.c \
				ft_count_exec_code_size.c \
				ft_count_num_len.c \
				ft_dis_add_elem.c \
				ft_dis_add_s.c \
				ft_dis_arg_treat.c \
				ft_dis_arg_types_treat.c \
				ft_dis_args_treat.c \
				ft_dis_ask_new_filename.c \
				ft_dis_bytecode_to_int32.c \
				ft_dis_check_file_exist.c \
				ft_dis_choose_new_filename.c \
				ft_dis_convert_start_filename.c \
				ft_dis_copy_filename.c \
				ft_dis_del_cor.c \
				ft_dis_elems_treat.c \
				ft_dis_error.c \
				ft_dis_exec_code_treat.c \
				ft_dis_free_struct.c \
				ft_dis_get_arg_type.c \
				ft_dis_get_size.c \
				ft_dis_init_elem.c \
				ft_dis_init_struct.c \
				ft_dis_is_arg_types_valid.c \
				ft_dis_parse_bytecode.c \
				ft_dis_parse_code.c \
				ft_dis_parse_int32.c \
				ft_dis_parse_string.c \
				ft_dis_read_write.c \
				ft_dis_set_arg_type.c \
				ft_dis_try_create_file.c \
				ft_dis_validate_types_code.c \
				ft_dis_valide_comment.c \
				ft_dis_valide_name.c \
				ft_dis_write_file.c \
				ft_disassemble.c \
				ft_free_asm_struct.c \
				ft_get_one_arg.c \
				ft_init_asm_struct.c \
				ft_init_n_add_token.c \
				ft_int32_to_bytecode.c \
				ft_is_filename.c \
				ft_is_label_char.c \
				ft_is_whitespace.c \
				ft_label_processing_n_pos_update.c \
				ft_label_saving_n_pos_update.c \
				ft_line_data_processing.c \
				ft_line_of_whitespaces_or_comment.c \
				ft_open_quotes_processing.c \
				ft_open_solution_file.c \
				ft_operation_processing_n_pos_update.c \
				ft_parse_file.c \
				ft_parse_line.c \
				ft_print_error.c \
				ft_print_help.c \
				ft_start_check_name_or_comment.c \
				ft_strjoin_n_free.c \
				ft_write_arg_type_code.c \
				ft_write_bytecode_to_file.c

SRC_DIR = ./sources/
SRC_ASM_DIR = ${SRC_DIR}asm/
SRC_CW_DIR = ${SRC_DIR}cw/

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_CW = $(addprefix $(SRC_CW_DIR), $(SRC_LIST_CW))
SRC_ASM = $(addprefix $(SRC_ASM_DIR), $(SRC_LIST_ASM))

#----------------------------------objects--------------------------------------

OBJ_DIR = ./objects/
OBJ_CW_DIR = ${OBJ_DIR}cw/
OBJ_ASM_DIR = ${OBJ_DIR}asm/

OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ_LIST_CW = $(patsubst %.c, %.o, $(SRC_LIST_CW))
OBJ_LIST_ASM = $(patsubst %.c, %.o, $(SRC_LIST_ASM))

OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))
OBJ_CW	= $(addprefix $(OBJ_CW_DIR), $(OBJ_LIST_CW))
OBJ_ASM	= $(addprefix $(OBJ_ASM_DIR), $(OBJ_LIST_ASM))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME_CW) $(NAME_ASM)

$(NAME_CW): $(LIBFT) $(OBJ_CW_DIR) $(OBJ_CW)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ_CW) -o $(NAME_CW)
	@echo "\n$(NAME_CW): $(GRN)$(NAME_CW) object files were created$(END)"
	@echo "$(NAME_CW): $(GRN)$(NAME_CW) was created$(END)"

$(NAME_ASM): $(LIBFT) $(OBJ_ASM_DIR) $(OBJ_ASM)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ_ASM) -o $(NAME_ASM)
	@echo "\n$(NAME_ASM): $(GRN)$(NAME_ASM) object files were created$(END)"
	@echo "$(NAME_ASM): $(GRN)$(NAME_ASM) was created$(END)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(GRN)$(OBJ_DIR) created$(END)"

$(OBJ_CW_DIR):
	@mkdir -p $(OBJ_CW_DIR)
	@echo "$(GRN)$(OBJ_CW DIR) created$(END)"

$(OBJ_ASM_DIR):
	@mkdir -p $(OBJ_ASM_DIR)
	@echo "$(GRN)$(OBJ_ASM_DIR) created$(END)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(OBJ_CW_DIR)%.o : $(SRC_CW_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(OBJ_ASM_DIR)%.o : $(SRC_ASM_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(LIBFT):
	@echo "$(GRN)Creating $(LIBFT)...$(END)"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(OBJ_DIR) deleted$(END)"
	@echo "$(RED)*.o files deleted$(END)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)$(LIBFT) deleted$(END)"
	@rm -f $(NAME_CW)
	@echo "$(NAME_CW): $(RED)$(NAME_CW) deleted$(END)"
	@rm -f $(NAME_ASM)
	@echo "$(NAME_ASM): $(RED)$(NAME_ASM) deleted$(END)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
