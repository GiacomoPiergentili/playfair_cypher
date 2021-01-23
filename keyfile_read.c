#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keyfile_read.h"
#include "utils.h"

void read_all(char *keyfile_path, kf *keyfile) {
    FILE *kfp = fopen(keyfile_path, "r");
    char *str = read_file(kfp);
    char *token = strtok(str, "\r\n");
    keyfile->alphabet->alphabet = token;
    keyfile->alphabet->flag = malloc(25 * sizeof(int));
    token = strtok(NULL, "\r\n");
    keyfile->missing_char = token[0];
    token = strtok(NULL, "\r\n");
    keyfile->special_char = token[0];
    token = strtok(NULL, "\r\n");
    keyfile->key->key = remove_spaces(token);
    keyfile->key->size = size_of_string(keyfile->key->key);
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
    for (int i = 0; i < size_of_string(key->key); i++) {
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