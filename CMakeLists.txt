cmake_minimum_required(VERSION 3.17.3)
project(corewar C)

set(CMAKE_C_STANDARD 90)

set (SOURCES
		sources/cw/init.c
		sources/cw/pl_init.c
		sources/cw/operation.c
		sources/cw/print.c
		sources/cw/terminate.c
		sources/cw/libft.c
		sources/commands/live.c
		sources/commands/ld.c
		sources/commands/sti.c
		sources/commands/st.c
		sources/commands/ldi.c
		sources/commands/zjmp.c
		sources/commands/add.c
		sources/commands/sub.c
		sources/commands/and.c
		sources/commands/or.c
		sources/commands/xor.c
		sources/commands/fork.c
		sources/commands/aff.c
		sources/cw/pl_order_of_players.c
		sources/cw/pl_check_flags.c
		sources/cw/pl_order_of_number.c
		sources/cw/pl_add_data_champion.c
		sources/cw/pl_check_magic_header.c sources/cw/vm_parce_args.c sources/cw/cr_set_args.c sources/cw/get_data.c)

set (SOURCES_CW
		sources/cw/corewar.c)
# ls -l ./sources/asm | awk '{print "sources/asm/"$9}'
set(SOURCES_ASM
		sources/asm/asm.c
		sources/asm/ft_dis_add_elem.c
		sources/asm/ft_dis_error_arg_types_code.c
		sources/asm/ft_asm_error.c
		sources/asm/ft_assemble.c
		sources/asm/ft_check_arg_type.c
		sources/asm/ft_check_end_newline.c
		sources/asm/ft_check_n_write_op_args.c
		sources/asm/ft_check_operation.c
		sources/asm/ft_check_quotes.c
		sources/asm/ft_check_read_argv_files.c
		sources/asm/ft_dis_code_types_warning.c
		sources/asm/ft_dis_warning_comment.c
		sources/asm/ft_count_exec_code_size.c
		sources/asm/ft_count_num_len.c
        sources/asm/ft_dis_add_s.c
		sources/asm/ft_dis_ask_new_filename.c
		sources/asm/ft_dis_check_file_exist.c
		sources/asm/ft_dis_choose_new_filename.c
		sources/asm/ft_dis_convert_start_filename.c
		sources/asm/ft_dis_copy_filename.c
		sources/asm/ft_dis_del_cor.c
		sources/asm/ft_dis_error.c
		sources/asm/ft_dis_free_struct.c
		sources/asm/ft_dis_init_struct.c
		sources/asm/ft_dis_read_write.c
		sources/asm/ft_dis_try_create_file.c
		sources/asm/ft_dis_write_file.c
		sources/asm/ft_disassemble.c
		sources/asm/ft_free_asm_struct.c
		sources/asm/ft_free_bytecode_parser.c
		sources/asm/ft_dis_get_arg_type.c
		sources/asm/ft_get_label_mention.c
		sources/asm/ft_get_one_arg.c
		sources/asm/ft_dis_get_size.c
		sources/asm/ft_init_asm_struct.c
		sources/asm/ft_init_n_add_label.c
		sources/asm/ft_init_n_add_mention.c
		sources/asm/ft_dis_init_element.c
		sources/asm/ft_int32_to_bytecode.c
		sources/asm/ft_dis_is_arg_types_valide.c
		sources/asm/ft_is_label_char.c
		sources/asm/ft_is_whitespace.c
		sources/asm/ft_label_processing_n_pos_update.c
		sources/asm/ft_label_saving_n_pos_update.c
		sources/asm/ft_dis_error_length.c
		sources/asm/ft_line_data_processing.c
		sources/asm/ft_line_of_whitespaces_or_comment.c
		sources/asm/ft_dis_warning_name.c
		sources/asm/ft_dis_error_opcode.c
		sources/asm/ft_open_quotes_processing.c
		sources/asm/ft_open_solution_file.c
		sources/asm/ft_operation_processing_n_pos_update.c
		sources/asm/ft_dis_parse_bytecode.c
		sources/asm/ft_dis_parse_code.c
		sources/asm/ft_parse_file.c
		sources/asm/ft_dis_parse_int32.c
		sources/asm/ft_parse_line.c
		sources/asm/ft_dis_parse_str.c
		sources/asm/ft_print_error.c
		sources/asm/ft_print_help.c
		sources/asm/ft_dis_treat_arg.c
		sources/asm/ft_dis_treat_arg_types.c
		sources/asm/ft_dis_treat_args.c
		sources/asm/ft_dis_args_treat.c
		sources/asm/ft_dis_error_register.c
		sources/asm/ft_search_label_exist.c
		sources/asm/ft_dis_set_arg_type.c
		sources/asm/ft_start_check_name_or_comment.c
		sources/asm/ft_strjoin_n_free.c
		sources/asm/ft_dis_terminate.c
		sources/asm/ft_transform_mentions.c
		sources/asm/ft_dis_validate_code_types.c
		sources/asm/ft_dis_validate_comment.c
		sources/asm/ft_dis_validate_name.c
		sources/asm/ft_write_arg_type_code.c
		sources/asm/ft_write_asm_file.c
		sources/asm/ft_write_bytecode_to_file.c
		sources/asm/ft_write_code_to_exec.c
		sources/asm/ft_write_exec_code_in_line.c
		sources/asm/ft_dis_treat_exec_code.c
		sources/asm/ft_dis_bytecode_to_int32.c
		sources/asm/ft_is_filename.c
        sources/asm/ft_is_op_char.c)

include_directories(includes)
include_directories(libft/inc)

add_subdirectory(libft)

add_executable(corewar ${SOURCES_CW} ${SOURCES})
add_executable(asm ${SOURCES_ASM} ${SOURCES})

target_link_libraries(asm libft)
target_link_libraries(corewar libft)

