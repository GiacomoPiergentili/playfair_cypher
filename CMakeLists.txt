cmake_minimum_required(VERSION 3.17)
project(playfair_cypher C)

set(CMAKE_C_STANDARD 99)

add_executable(playfair_cypher main.c utils.c keyfile_read.c matrix_gen.c secretmessage_encode.c secretmessage_decode.c matrix_utils.c)