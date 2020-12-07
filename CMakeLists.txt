cmake_minimum_required(VERSION 3.17.3)
project(corewar C)

set(CMAKE_C_STANDARD 90)

set(SOURCES
		sources/cw/init.c
		sources/cw/pl_init.c
		sources/cw/operation.c
		sources/cw/print.c
		sources/cw/terminate.c
		sources/cw/libft.c
		sources/cw/commands/live.c
		sources/cw/commands/ld.c
		sources/cw/commands/sti.c
		sources/cw/commands/st.c
		sources/cw/commands/ldi.c
		sources/cw/commands/zjmp.c
		sources/cw/commands/add.c
		sources/cw/commands/sub.c
		sources/cw/commands/and.c
		sources/cw/commands/or.c
		sources/cw/commands/xor.c
		sources/cw/commands/fork.c
		sources/cw/commands/aff.c)

set(SOURCES_CW
        sources/cw/corewar.c)

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
		sources/asm/ft_label_saving_n_pos_update.c
		sources/asm/ft_operation_processing_n_pos_update.c
		sources/asm/ft_label_processing_n_pos_update.c
		sources/asm/ft_is_label_char.c
		sources/asm/ft_dis_error.c
		sources/asm/ft_dis_init_struct.c
		sources/asm/ft_dis_choose_new_filename.c
		sources/asm/ft_dis_check_file_exist.c
		sources/asm/ft_dis_try_create_file.c
		sources/asm/ft_dis_free_struct.c
		sources/asm/ft_dis_ask_new_filename.c
		sources/asm/ft_check_n_write_op_args.c
		sources/asm/ft_get_one_arg.c
		sources/asm/ft_dis_copy_filename.c
		sources/asm/ft_dis_add_s.c
		sources/asm/ft_dis_del_cor.c
		sources/asm/ft_dis_convert_start_filename.c
		sources/asm/ft_get_one_arg.c
		sources/asm/ft_count_num_len.c
		sources/asm/ft_check_arg_type.c
		sources/asm/ft_write_arg_type_code.c
		sources/asm/ft_count_exec_code_size.c
		sources/asm/ft_dis_read_write.c
		sources/asm/ft_dis_exec_code_treat.c sources/asm/ft_dis_valide_name.c sources/asm/ft_dis_valide_comment.c sources/asm/ft_dis_validate_types_code.c sources/asm/ft_dis_is_arg_types_valid.c sources/asm/ft_dis_add_elem.c sources/asm/ft_dis_get_arg_type.c sources/asm/ft_dis_set_arg_type.c sources/asm/ft_dis_arg_types_treat.c sources/asm/ft_dis_get_size.c sources/asm/ft_dis_arg_treat.c sources/asm/ft_dis_args_treat.c sources/asm/ft_dis_init_elem.c sources/asm/ft_dis_elems_treat.c sources/asm/ft_dis_bytecode_to_int32.c sources/asm/ft_dis_parse_int32.c sources/asm/ft_dis_parse_string.c sources/asm/ft_dis_parse_code.c sources/asm/ft_dis_parse_bytecode.c sources/asm/ft_dis_write_file.c)

include_directories(includes)
include_directories(libft/inc)

add_subdirectory(libft)

add_executable(corewar ${SOURCES_CW} ${SOURCES})
add_executable(asm ${SOURCES_ASM} ${SOURCES})

target_link_libraries(asm libft)
target_link_libraries(corewar libft)

