#include <stdio.h>
#include <stdlib.h>
#include "message_utils.h"
#include "utils.h"
#include "secretmessage_encode.h"
#include "matrix_utils.h"

char *read_message(char *secretemessage_path, char missing_alphabet_letter, char missing_char) {
    FILE *smp = fopen(secretemessage_path, "r");
    check_exist(smp, secretemessage_path);
    char *str = read_file(smp);
    str = remove_spaces(str);
    return remove_missing_alphabet_letter(str, missing_alphabet_letter, missing_char);
}

sm *init_message_E(char *str) {
    sm *message = malloc(sizeof(sm) + 1);
    message->size = find_m_size(str);
    message->pairs = initialize_matrix(message->pairs, message->size / 2, 2);
    message->encoded_pairs = initialize_matrix(message->encoded_pairs, message->size / 2, 2);
    return message;
}

sm *create_message(char *secretemessage_path, kf *keyfile) {
    char *str = read_message(secretemessage_path, keyfile->missing_alphabet_letter, keyfile->missing_char);
    sm *message = init_message_E(str);
    fill_pairs_E(message->pairs, str, message->size, keyfile->special_char);
    fill_encoded_pairs_E(message->pairs, message->encoded_pairs, keyfile->matrix, message->size);
    return message;
}

void fill_pairs_E(char **pairs, char *str, int size_m, char special_c) {
    int i = 0;
    for (int r = 0; r < size_m / 2; r++) {
        for (int c = 0; c < 2; c++) {
            if (i < size_m) {
                if (c == 0) {
                    pairs[r][c] = str[i];
                    i++;
                } else {
                    if (pairs[r][0] == str[i]) {
                        pairs[r][1] = special_c;
                    } else {
                        pairs[r][1] = str[i];
                        i++;
                    }
                }
            }
        }
    }
    if (pairs[size_m / 2 - 1][1] == '\000')
        pairs[size_m / 2 - 1][1] = special_c;
}


void fill_encoded_pairs_E(char **pairs, char **encoded_pairs, char **matrix, int size_m) {
    int pos1[] = {0, 0};
    int pos2[] = {0, 0};
    for (int r = 0; r < size_m / 2; r++) {
        find_position(pos1, matrix, pairs[r][0]);
        find_position(pos2, matrix, pairs[r][1]);
        if (pos1[0] != pos2[0] && pos1[1] != pos2[1]) {
            different_r_c(encoded_pairs, matrix, pos1, pos2, r);
        } else if (pos1[0] == pos2[0]) {
            same_row(encoded_pairs, matrix, pos1, pos2, r);
        } else {
            same_column(encoded_pairs, matrix, pos1, pos2, r);

        }
    }
}

void different_r_c(char **encoded_pairs, char **matrix, int pos1[], int pos2[], int r) {
    encoded_pairs[r][0] = matrix[pos1[0]][pos2[1]];
    encoded_pairs[r][1] = matrix[pos2[0]][pos1[1]];
}

void same_row(char **encoded_pairs, char **matrix, int pos1[], int pos2[], int r) {
    if (pos1[1] == 4) {
        encoded_pairs[r][0] = matrix[pos1[0]][0];
        encoded_pairs[r][1] = matrix[pos2[0]][pos2[1] + 1];
    } else if (pos2[1] == 4) {
        encoded_pairs[r][0] = matrix[pos1[0]][pos1[1] + 1];
        encoded_pairs[r][1] = matrix[pos2[0]][0];
    } else {
        encoded_pairs[r][0] = matrix[pos1[0]][pos1[1] + 1];
        encoded_pairs[r][1] = matrix[pos1[0]][pos2[1] + 1];
    }
}

void same_column(char **encoded_pairs, char **matrix, int pos1[], int pos2[], int r) {
    if (pos1[0] == 4) {
        encoded_pairs[r][0] = matrix[0][pos1[1]];
        encoded_pairs[r][1] = matrix[pos2[0] + 1][pos2[1]];
    } else if (pos2[0] == 4) {
        encoded_pairs[r][0] = matrix[pos1[0] + 1][pos1[1]];
        encoded_pairs[r][1] = matrix[0][pos2[1]];
    } else {
        encoded_pairs[r][0] = matrix[pos1[0] + 1][pos1[1]];
        encoded_pairs[r][1] = matrix[pos2[0] + 1][pos2[1]];
    }
}