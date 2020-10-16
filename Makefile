# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghael <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/11 18:19:54 by cghael            #+#    #+#              #
#    Updated: 2020/10/11 18:29:57 by cghael           ###   ########.fr        #
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

SRC_LIST =
SRC_LIST_CW = corewar.c
SRC_LIST_ASM = asm.c \
				ft_asm_error.c \
				ft_assemble.c \
				ft_check_read_argv_files.c \
				ft_disassemble.c \
				ft_free_asm_struct.c \
				ft_init_asm_struct.c \
				ft_is_filename.c \
				ft_print_help.c \
				ft_open_solution_file.c \
				ft_int32_to_bytecode.c \
				ft_parse_file.c

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
