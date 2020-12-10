#ifndef PLAYFAIR_CYPHER_MATRIX_UTILS_H
#define PLAYFAIR_CYPHER_MATRIX_UTILS_H

char **initialize_matrix(char **matrix, int nr, int nc);
void free_matrix(char **matrix);
void print_matrix(char **matrix, int nr, int nc);
#endif //PLAYFAIR_CYPHER_MATRIX_UTILS_H
