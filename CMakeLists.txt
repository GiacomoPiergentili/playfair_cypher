cmake_minimum_required(VERSION 3.16.3)
project(playfair_cypher C)

set(CMAKE_C_STANDARD 99)

add_executable(playfair main.c utils.c keyfile_read.c keyfile_gen.c secretmessage_encode.c secretmessage_decode.c matrix_utils.c commands.c file_utils.c message_utils.c)
