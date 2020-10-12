cmake_minimum_required(VERSION 3.15)
project(corewar C)

set(CMAKE_C_STANDARD 90)

set(SOURCES_CW
        sources/corewar.c)

set(SOURCES_ASM
        sources/asm.c)

include_directories(includes)
include_directories(libft/inc)

add_subdirectory(libft)

add_executable(corewar ${SOURCES_CW})
add_executable(asm ${SOURCES_ASM})

target_link_libraries(asm libft)
target_link_libraries(corewar libft)

