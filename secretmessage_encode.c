#include <stdio.h>
#include "stdlib.h"
#include "secretmessage_encode.h"
#include "utils.h"
#include "matrix_utils.h"

char *read_message(char *secretemessage_path) {
    FILE *smp = fopen(secretemessage_path, "r");
    char *str = read_file(smp);
    return remove_spaces(str);
}

void create_message(char *secretemessage_path) {
    char *str = read_message(secretemessage_path);
    sm *message = malloc(sizeof(sm) + 1);
    message->size = find_m_size(str);
    message->pairs = initialize_matrix(message->pairs, message->size / 2, 2);
    printf("\n%d\n\n", message->size);
    fill(message->pairs, str, message->size, 'X');
    print_matrix(message->pairs, message->size / 2, 2);
}

void fill(char **matrix, char *str, int size_m, char special_c) {
    int i = 0;
    for (int r = 0; r < size_m / 2; r++) {
        for (int c = 0; c < 2; c++) {
            if (i < size_m) {
                if (c == 0) {
                    matrix[r][c] = str[i];
                    i++;
                } else {
                    if (matrix[r][0] == str[i]) {
                        matrix[r][1] = special_c;
                    } else {
                        matrix[r][1] = str[i];
                        i++;
                    }
                }
            }
        }
    }
}

int find_m_size(char *str) {
    int size = 0;
    int size_str = size_of_string(str);
    for (int i = 0; i < size_str; i++) {
        if (str[i] == str[i + 1]) {
            size += 2;
        } else {
            size += 2;
            i++;
        }
    }
    if (size % 2 != 0)
        size++;
    return size;
}