#ifndef PLAYFAIR_CYPHER_MATRIX_GEN_H
#define PLAYFAIR_CYPHER_MATRIX_GEN_H

#include "keyfile_read.h"

char **initialize_matrix(char **matrix);
void free_matrix(char **matrix);
kf *complete_keyfile(char *keyfile_path);
void fill_matrix(char **matrix, kf *keyfile);
void write_key(char **matrix, k *key, int *last_r, int *last_c);
void write_alphabet(char **matrix, al *alphabet, int *last_r, int *last_c);
void print_matrix(char **matrix);
void run1(char *path);


#endif //PLAYFAIR_CYPHER_MATRIX_GEN_H
