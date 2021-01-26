#include <string.h>
#include <stdlib.h>
#include "message_utils.h"
#include "matrix_utils.h"

int find_m_size(char *str) {
    int size = 0;
    int size_str = strlen(str);
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

char *remove_missing_alphabet_letter(char *str, char missing_alphabet_letter, char missing_char) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == missing_alphabet_letter)
            str[i] = missing_char;
    }
    return str;
}

void find_position(int *pos, char **matrix, char letter) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (matrix[r][c] == letter) {
                pos[0] = r;
                pos[1] = c;
            }
        }
    }
}

void free_message(sm *message) {
    free_matrix(message->pairs, message->size/2);
    free_matrix(message->encoded_pairs, message->size/2);
    free(message);
    message = NULL;
}

