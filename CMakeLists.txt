cmake_minimum_required(VERSION 3.17.1)
project(corewar C)

set(CMAKE_C_STANDARD 90)

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
        sources/asm/ft_check_read_argv_files.c)

include_directories(includes)
include_directories(libft/inc)

add_subdirectory(libft)

add_executable(corewar ${SOURCES_CW})
add_executable(asm ${SOURCES_ASM})

target_link_libraries(asm libft)
target_link_libraries(corewar libft)

