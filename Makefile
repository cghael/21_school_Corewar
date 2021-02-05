# **************************************************************************** #
#																												        #
#																				       :::      ::::::::    #
#    Makefile																   :+:      :+:    :+:    #
#																				   +:+ +:+         +:+      #
#    By: ksemele <marvin@42.fr>								 +#+  +:+       +#+         #
#																         +#+#+#+#+#+   +#+				  #
#    Created: 2021/01/31 13:26:45 by ksemele				 #+#    #+#				    #
#    Updated: 2021/01/31 13:43:32 by ksemele				###   ########.fr        #
#																												        #
# **************************************************************************** #

NAME_CW = corewar
NAME_ASM = asm

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lncurses
INCLUDES = -I$(HEADERS_DIR)

#----------------------------------headers--------------------------------------

HEADERS_LIST = corewar.h \
				asm.h

HEADERS_DIR = includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#----------------------------------sources--------------------------------------
# to update lists: ls -l ./sources/asm | awk '{print $9, "\\"}'

SRC_CW_MAIN = corewar.c

SRC_LIST_CW =	init.c \
				print.c \
				pl_init.c \
				get_data.c \
				operation.c \
				terminate.c \
				cr_set_args.c \
				vm_parce_args.c \
				pl_check_flags.c \
				pl_order_of_number.c \
				pl_order_of_players.c \
				pl_add_data_champion.c \
				pl_check_magic_header.c \
				ft_visualiser.c \
				vi_operation.c \
				libft.c
SRC_ASM_MAIN = asm.c

SRC_LIST_ASM =	ft_asm_error.c \
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
				ft_dis_args_treat.c \
				ft_dis_ask_new_filename.c \
				ft_dis_bytecode_to_int32.c \
				ft_dis_check_file_exist.c \
				ft_dis_choose_new_filename.c \
				ft_dis_code_types_warning.c \
				ft_dis_convert_start_filename.c \
				ft_dis_copy_filename.c \
				ft_dis_del_cor.c \
				ft_dis_error_free.c \
				ft_dis_error_arg_types_code.c \
				ft_dis_error_length.c \
				ft_dis_error_opcode.c \
				ft_dis_error_register.c \
				ft_dis_free_struct.c \
				ft_dis_get_arg_type.c \
				ft_dis_get_size.c \
				ft_dis_init_element.c \
				ft_dis_init_struct.c \
				ft_dis_is_arg_types_valide.c \
				ft_dis_parse_bytecode.c \
				ft_dis_parse_code.c \
				ft_dis_parse_int32.c \
				ft_dis_parse_str.c \
				ft_dis_read_write.c \
				ft_dis_set_arg_type.c \
				ft_dis_terminate.c \
				ft_dis_treat_arg.c \
				ft_dis_treat_arg_types.c \
				ft_dis_treat_args.c \
				ft_dis_treat_exec_code.c \
				ft_dis_try_create_file.c \
				ft_dis_validate_code_types.c \
				ft_dis_validate_comment.c \
				ft_dis_validate_name.c \
				ft_dis_warning_comment.c \
				ft_dis_warning_name.c \
				ft_dis_write_file.c \
				ft_disassemble.c \
				ft_free_asm_struct.c \
				ft_get_label_mention.c \
				ft_get_one_arg.c \
				ft_init_asm_struct.c \
				ft_init_n_add_label.c \
				ft_init_n_add_mention.c \
				ft_int32_to_bytecode.c \
				ft_is_filename.c \
				ft_is_label_char.c \
				ft_is_op_char.c \
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
				ft_search_label_exist.c \
				ft_start_check_name_or_comment.c \
				ft_strjoin_n_free.c \
				ft_transform_mentions.c \
				ft_write_arg_type_code.c \
				ft_write_bytecode_to_file.c \
				ft_write_code_to_exec.c \
				ft_write_exec_code_in_line.c

SRC_LIST_COMMS = ld.c \
				st.c \
				or.c \
				sti.c \
				add.c \
				sub.c \
				and.c \
				aff.c \
				xor.c \
				ldi.c \
				zjmp.c \
				live.c \
				fork.c

SRC_LIST_LIB = 	ft_atoi.c\
				ft_bzero.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putnbr.c\
				ft_putnbr_fd.c\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strnequ.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strsepcut.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_lstnew.c\
				ft_lstdelone.c\
				ft_lstdel.c\
				ft_lstadd.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstaddend.c\
				ft_list_size.c\
				ft_list_clear.c\
				ft_word_count.c\
				ft_free_tdarr.c\
				ft_node_del.c\
				ft_get_next_line.c \
				ft_free_two_dem_str.c \
				ft_str_is_int.c \
						ft_abs.c \
						ft_add_specials.c \
						ft_buff_finded_percent.c \
						ft_buff_free.c \
						ft_buff_no_percent.c \
						ft_buff_print_free.c \
						ft_buff_print_n_len.c \
						ft_buff_treated_percent.c \
						ft_bzero_buf_n_set_pointers.c \
						ft_choose_func.c \
						ft_dollar_arg.c \
						ft_dollar_treat.c \
						ft_error_exit.c \
						ft_final_print_n_free_rt_len.c \
						ft_find_digit.c \
						ft_find_in_def.c \
						ft_isbigger.c \
						ft_i64toa_base.c \
						ft_num_to_str.c \
						ft_parse_flags.c \
						ft_parse_spec.c \
						ft_parsing.c \
						ft_percent_treat.c \
						ft_precision_treat.c \
						ft_printf.c \
						ft_strcpy_dptp.c \
						ft_strpcpy.c \
						ft_width_treat.c \
						ft_u64toa_base.c \
						ft_c.c \
						ft_di.c \
						ft_o.c \
						ft_p.c \
						ft_s.c \
						ft_u.c \
						ft_x.c \
						ft_b.c \
						ft_f.c \
						ft_count_float.c \
						ft_get_integer.c \
						ft_get_divisional.c \
						ft_round_float.c \
						ft_exeption_treat.c \
						ft_integer_to_str.c \
						ft_add_dig_to_int.c \
						ft_width_n_precision.c \
						ft_add_float_to_str.c \
						ft_put_div_by_one.c

SRC_DIR = ./sources/
SRC_ASM_DIR = ${SRC_DIR}asm/
SRC_CW_DIR = ${SRC_DIR}cw/
SRC_COMMS_DIR = ${SRC_DIR}commands/
SRC_LIB_DIR = ${SRC_DIR}lib/

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_CW = $(addprefix $(SRC_CW_DIR), $(SRC_LIST_CW))
SRC_ASM = $(addprefix $(SRC_ASM_DIR), $(SRC_LIST_ASM))
SRC_COMMS = $(addprefix $(SRC_COMMS_DIR), $(SRC_LIST_COMMS))
SRC_LIB = $(addprefix $(SRC_LIB_DIR), $(SRC_LIST_LIB))

#----------------------------------objects--------------------------------------

OBJ_DIR = ./objects/
OBJ_CW_DIR = ${OBJ_DIR}cw/
OBJ_ASM_DIR = ${OBJ_DIR}asm/
OBJ_COMMS_DIR = ${OBJ_DIR}commands/
OBJ_LIB_DIR = ${OBJ_DIR}lib/

OBJ_LIST_CW = $(patsubst %.c, %.o, $(SRC_LIST_CW))
OBJ_LIST_CW_MAIN = $(patsubst %.c, %.o, $(SRC_CW_MAIN))
OBJ_LIST_ASM = $(patsubst %.c, %.o, $(SRC_LIST_ASM))
OBJ_LIST_ASM_MAIN = $(patsubst %.c, %.o, $(SRC_ASM_MAIN))
OBJ_LIST_COMMS = $(patsubst %.c, %.o, $(SRC_LIST_COMMS))
OBJ_LIST_LIB = $(patsubst %.c, %.o, $(SRC_LIST_LIB))

OBJ_CW	= $(addprefix $(OBJ_CW_DIR), $(OBJ_LIST_CW))
OBJ_CW_MAIN = $(addprefix $(OBJ_CW_DIR), $(OBJ_LIST_CW_MAIN))
OBJ_ASM	= $(addprefix $(OBJ_ASM_DIR), $(OBJ_LIST_ASM))
OBJ_ASM_MAIN = $(addprefix $(OBJ_ASM_DIR), $(OBJ_LIST_ASM_MAIN))
OBJ_COMMS = $(addprefix $(OBJ_COMMS_DIR), $(OBJ_LIST_COMMS))
OBJ_LIB = $(addprefix $(OBJ_LIB_DIR), $(OBJ_LIST_LIB))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME_CW) $(NAME_ASM)

$(NAME_CW): $(OBJ_LIB_DIR) $(OBJ_LIB) $(OBJ_COMMS_DIR) $(OBJ_COMMS) $(OBJ_CW_DIR) $(OBJ_CW) $(OBJ_CW_MAIN)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ_CW) $(OBJ_COMMS) $(OBJ_CW_MAIN) $(OBJ_LIB) -o $(NAME_CW)
	@echo "\n$(NAME_CW): $(GRN)$(NAME_CW) object files were created$(END)"
	@echo "$(NAME_CW): $(GRN)$(NAME_CW) was created$(END)"

$(NAME_ASM): $(OBJ_LIB_DIR) $(OBJ_LIB) $(OBJ_COMMS_DIR) $(OBJ_COMMS) $(OBJ_ASM_DIR) $(OBJ_ASM) $(OBJ_CW_DIR) $(OBJ_CW) $(OBJ_ASM_MAIN)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ_ASM) $(OBJ_COMMS) $(OBJ_CW) $(OBJ_ASM_MAIN) $(OBJ_LIB) -o $(NAME_ASM)
	@echo "\n$(NAME_ASM): $(GRN)$(NAME_ASM) object files were created$(END)"
	@echo "$(NAME_ASM): $(GRN)$(NAME_ASM) was created$(END)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_LIB_DIR): $(OBJ_DIR)
	@mkdir -p $(OBJ_LIB_DIR)

$(OBJ_COMMS_DIR): $(OBJ_DIR)
	@mkdir -p $(OBJ_COMMS_DIR)

$(OBJ_CW_DIR): $(OBJ_DIR)
	@mkdir -p $(OBJ_CW_DIR)

$(OBJ_ASM_DIR): $(OBJ_DIR)
	@mkdir -p $(OBJ_ASM_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(OBJ_CW_DIR)%.o : $(SRC_CW_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(OBJ_ASM_DIR)%.o : $(SRC_ASM_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(OBJ_COMMS_DIR)%.o : $(SRC_COMMS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(OBJ_LIB_DIR)%.o : $(SRC_LIB_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(OBJ_DIR) deleted$(END)"
	@echo "$(RED)*.o files deleted$(END)"

fclean: clean
	@rm -f $(NAME_CW)
	@echo "$(NAME_CW): $(RED)$(NAME_CW) deleted$(END)"
	@rm -f $(NAME_ASM)
	@echo "$(NAME_ASM): $(RED)$(NAME_ASM) deleted$(END)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
