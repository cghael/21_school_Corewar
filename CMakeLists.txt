cmake_minimum_required(VERSION 3.17.3)
project(corewar C)

set(CMAKE_C_STANDARD 90)

set(SOURCES_CW
        sources/cw/corewar.c includes/errors.h)

set(SOURCES_ASM
		sources/asm/asm.c
		sources/asm/ft_is_filename.c
		sources/asm/ft_assemble.c
		sources/asm/ft_disassemble.c
		sources/asm/ft_print_help.c
		sources/asm/ft_init_asm_struct.c
		sources/asm/ft_asm_error.c
		sources/asm/ft_free_asm_struct.c
		sources/asm/ft_check_read_argv_files.c
		sources/asm/ft_write_bytecode_to_file.c
		sources/asm/ft_open_solution_file.c
		sources/asm/ft_int32_to_bytecode.c
		sources/asm/ft_parse_file.c
		sources/asm/ft_is_whitespace.c
		sources/asm/ft_print_error.c
		sources/asm/ft_parse_line.c
		sources/asm/ft_line_data_processing.c
		sources/asm/ft_start_check_name_or_comment.c
		sources/asm/ft_line_of_whitespaces_or_comment.c
		sources/asm/ft_check_quotes.c
		sources/asm/ft_open_quotes_processing.c
		sources/asm/ft_strjoin_n_free.c
		sources/asm/ft_check_operation.c
		sources/asm/ft_init_n_add_token.c
		sources/asm/ft_check_end_newline.c
		sources/asm/ft_label_saving_n_pos_update.c sources/asm/ft_operation_processing_n_pos_update.c sources/asm/ft_label_processing_n_pos_update.c sources/asm/ft_is_label_char.c sources/asm/ft_dis_error.c sources/asm/ft_dis_init_struct.c sources/asm/ft_dis_correct_input.c sources/asm/ft_dis_choose_new_filename.c sources/asm/ft_dis_filename_treat.c sources/asm/ft_dis_check_file_exist.c)

include_directories(includes)
include_directories(libft/inc)

add_subdirectory(libft)

add_executable(corewar ${SOURCES_CW})
add_executable(asm ${SOURCES_ASM})

target_link_libraries(asm libft)
target_link_libraries(corewar libft)

