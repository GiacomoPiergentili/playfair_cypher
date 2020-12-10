#include <stdio.h>
#include <stdlib.h>
#include "matrix_gen.h"
#include "matrix_utils.h"
#include "keyfile_read.h"

kf *complete_keyfile(char *keyfile_path) {
    kf *keyfile = malloc(sizeof(kf) + 1);
    keyfile->alphabet = malloc(sizeof(al) + 1);
    keyfile->key = malloc(sizeof(k) + 1);
    read_all(keyfile_path, keyfile);
    find_repetition(keyfile->key);
    clear_alphabet(keyfile->alphabet, keyfile->key);
    return keyfile;
}

void fill_matrix(char **matrix, kf *keyfile) {
    int last_r, last_c;
    write_key(matrix, keyfile->key, &last_r, &last_c);
    write_alphabet(matrix, keyfile->alphabet, &last_r, &last_c);
    print_matrix(matrix);
}

void write_key(char **matrix, k *key, int *last_r, int *last_c) {
    int last_char_pos = -1;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            for (int i = last_char_pos + 1; i < key->size; i++) {
                if (key->flag[i] == 0) {
                    matrix[r][c] = key->key[i];
                    last_char_pos = i;
                    *last_r = r;
                    *last_c = c;
                    break;
                }
            }
        }
    }
}

void write_alphabet(char **matrix, al *alphabet, int *last_r, int *last_c) {
    int last_alphabet_pos = -1;
    int r, c;
    if ((*last_r < 4 && *last_c < 4) || (*last_r == 4 && *last_c < 4)) {
        r = *last_r;
        c = *last_c + 1;
    } else if (*last_r < 4 && *last_c == 4) {
        r = *last_r + 1;
        c = 0;
    } else if (*last_r == 4 && *last_c == 4) {
        exit(0);
    }
    for (; r < 5; r++) {
        if (c == 5)
            c = 0;
        for (; c < 5; c++) {
            for (int i = last_alphabet_pos + 1; i < 25; i++) {
                if (alphabet->flag[i] == 0) {
                    matrix[r][c] = alphabet->alphabet[i];
                    last_alphabet_pos = i;
                    break;
                }
            }
        }
    }
}

void run1(char *path) {
    char **matrix = NULL;
    matrix = initialize_matrix(matrix);
    kf *keyfile = complete_keyfile(path);
    fill_matrix(matrix, keyfile);
}

