#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "matrix_utils.h"
#include "secretmessage_encode.h"
#include "secretmessage_decode.h"

char *read_encoded_message(char *encodedmessage_path) {
    FILE *smp = fopen(encodedmessage_path, "r");
    char *str = read_file(smp);
    return (remove_spaces(str));
}

void create_encoded_message(char *encodedmessage_path, kf *keyfile) {
    char *str = read_encoded_message(encodedmessage_path);
    sm *message = init_message_D(str);
    fill_encoded_pairs_D(size_of_string(str), str, message->encoded_pairs, keyfile->missing_alphabet_letter);
    fill_pairs_D(message->pairs, message->encoded_pairs, keyfile->matrix, message->size);
    print_matrix(message->pairs, message->size / 2, 2);
}

sm *init_message_D(char *str) {
    sm *message = malloc(sizeof(sm) + 1);
    message->size = size_of_string(str);
    message->pairs = initialize_matrix(message->pairs, message->size / 2, 2);
    message->encoded_pairs = initialize_matrix(message->encoded_pairs, message->size / 2, 2);
    return message;
}

void fill_encoded_pairs_D(int size, char *str, char **encoded_pairs, char missing_alphabet_letter) {
    check_odd(str);
    int i = 0;
    for (int r = 0; r < size / 2; r++) {
        if (i < size) {
            if (str[i] == missing_alphabet_letter || str[i + 1] == missing_alphabet_letter) {
                printf("%s", "CAN'T DECYPHER");
                exit(0);
            } else {
                encoded_pairs[r][0] = str[i];
                encoded_pairs[r][1] = str[i + 1];
                i += 2;
            }
        }
    }
}

void fill_pairs_D(char **pairs, char **encoded_pairs, char **matrix, int size) {
    int pos1[] = {0, 0};
    int pos2[] = {0, 0};
    for (int r = 0; r < size / 2; r++) {
        find_position(pos1, matrix, encoded_pairs[r][0]);
        find_position(pos2, matrix, encoded_pairs[r][1]);
        if (pos1[0] != pos2[0] && pos1[1] != pos2[1]) { //righe e colonne diverse
            different_r_c_D(pairs, matrix, pos1, pos2, r);
        } else if (pos1[0] == pos2[0]) { //stessa riga
            same_row_D(pairs, matrix, pos1, pos2, r);
        } else if (pos1[1] == pos2[1]) { //stessa colonna
            same_column_D(pairs, matrix, pos1, pos2, r);
        } else {
            printf("%s", "CAN'T DECYPHER");
        }
    }
}

void different_r_c_D(char **pairs, char **matrix, int pos1[], int pos2[], int r) {
    pairs[r][0] = matrix[pos1[0]][pos2[1]];
    pairs[r][1] = matrix[pos2[0]][pos1[1]];
}

void same_row_D(char **pairs, char **matrix, int pos1[], int pos2[], int r) {
    if (pos1[1] == 0) {
        pairs[r][0] = matrix[pos1[0]][4];
        pairs[r][1] = matrix[pos2[0]][pos2[1] - 1];
    } else if (pos2[1] == 0) {
        pairs[r][0] = matrix[pos1[0]][pos1[1] - 1];
        pairs[r][1] = matrix[pos2[0]][4];
    } else {
        pairs[r][0] = matrix[pos1[0]][pos1[1] - 1];
        pairs[r][1] = matrix[pos1[0]][pos2[1] - 1];
    }
}

void same_column_D(char **pairs, char **matrix, int pos1[], int pos2[], int r) {
    if (pos1[0] == 0) {
        pairs[r][0] = matrix[4][pos1[1]];
        pairs[r][1] = matrix[pos2[0] - 1][pos2[1]];
    } else if (pos2[0] == 0) {
        pairs[r][0] = matrix[pos1[0] - 1][pos1[1]];
        pairs[r][1] = matrix[4][pos2[1]];
    } else {
        pairs[r][0] = matrix[pos1[0] - 1][pos1[1]];
        pairs[r][1] = matrix[pos2[0] - 1][pos2[1]];
    }
}

void check_odd(char *str) {
    if (size_of_string(str) % 2 != 0) {
        printf("%s", "CAN'T DECYPHER");
        exit(0);
    }
}
