#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keyfile_read.h"
#include "utils.h"
#include "matrix_utils.h"

void read_all(char *keyfile_path, kf *keyfile) {
    FILE *kfp = fopen(keyfile_path, "r");
    check_exist(kfp, keyfile_path);
    char *str = read_file(kfp);
    check_keyfile(str);
    char *token = strtok(str, "\r\n");
    keyfile->alphabet->alphabet = token;
    check_alphabet(keyfile->alphabet);
    keyfile->alphabet->flag = malloc(25 * sizeof(int));
    token = strtok(NULL, "\r\n");
    keyfile->missing_char = token[0];
    token = strtok(NULL, "\r\n");
    keyfile->special_char = token[0];
    token = strtok(NULL, "\r\n");
    keyfile->key->key = remove_spaces(token);
    keyfile->key->size = strlen(keyfile->key->key);
    keyfile->key->flag = malloc(keyfile->key->size * sizeof(int));
}

void find_repetition(k *key) {
    for (int i = 0; i < key->size; i++) {
        if (key->flag[i] == 1) {
            continue;
        } else {
            for (int j = i + 1; j < key->size; j++) {
                if (key->flag[j] == 1) {
                    continue;
                } else if (key->key[i] == key->key[j]) {
                    key->flag[j] = 1;
                }
            }
        }
    }
}

void clear_alphabet(al *alphabet, k *key) {
    for (int i = 0; i < strlen(key->key); i++) {
        if (key->flag[i] == 0) {
            for (int j = 0; j < 25; j++) {
                if (key->key[i] == alphabet->alphabet[j]) {
                    alphabet->flag[j] = 1;
                    break;
                }
            }
        }
    }
}

char find_missing_letter(al *alphabet) {
    char f_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    int j;
    int found;
    while (i < 26) {
        found = 0;
        j = 0;
        while (j < 25 && found == 0) {
            if (alphabet->alphabet[j] == f_alphabet[i])
                found = 1;
            else
                j++;
        }
        if (found == 0)
            return f_alphabet[i];
        i++;
    }
}

void free_alphabet(al *alphabet) {
    free(alphabet->alphabet);
    alphabet->alphabet = NULL;
    free(alphabet->flag);
    alphabet->flag = NULL;
    free(alphabet);
    alphabet = NULL;
}

void free_key(k *key) {
    free(key->flag);
    key->flag = NULL;
    free(key);
    key = NULL;
};

void free_keyfile(kf *keyfile) {
    free_alphabet(keyfile->alphabet);
    free_key(keyfile->key);
    free_matrix(keyfile->matrix, 5);
    free(keyfile);
    keyfile = NULL;
};

void check_keyfile(char *str) {
    char *str1 = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(str1, str);
    char *token = strtok(str1, "\r\n");;
    for (int i = 0; i < 4; i++) {
        if (token == NULL) {
            printf("THE KEYFILE MISSES ONE OR MORE ARGUMENTS");
            exit(1);
        }else if ((i == 1 || i == 2) && strlen(token) > 1) {
            printf("MISSING OR SPECIAL LETTER SHOULD BE ONLY ONE CHARACTER");
            exit(1);
        } else {
            token = strtok(NULL, "\r\n");
        }
    }
    free(str1);
}

void check_alphabet(al *alphabet) {
    if (strlen(alphabet->alphabet) > 25) {
        printf("ALPHABET SHOULD BE LESS THAN 25 CHARACTERS");
        exit(1);
    }
    for (int i = 0; i < strlen(alphabet->alphabet); i++) {
        for (int j = i + 1; j < strlen(alphabet->alphabet); j++) {
            if (alphabet->alphabet[i] == alphabet->alphabet[j]) {
                printf("ALPHABET CONTAINS 2 TIMES OR MORE THE SAME LETTER");
                exit(1);
            }
        }
    }
}