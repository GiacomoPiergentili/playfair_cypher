#include "matrix_utils.h"
#include "stdlib.h"
#include "stdio.h"

char **initialize_matrix(char **matrix) {
    int i;
    matrix = (char **) calloc(5, sizeof(char *));
    for (i = 0; i < 5; i++) {
        matrix[i] = (char *) calloc(5, sizeof(char));
    }
    return matrix;
}

void free_matrix(char **matrix) {
    if (matrix != NULL) {
        for (int i = 0; i < 5; ++i) {
            free(matrix[i]);
            matrix[i] = NULL;
        }
        free(matrix);
        matrix = NULL;
    }
}


void print_matrix(char **matrix) {
    int row, columns;
    for (row = 0; row < 5; row++) {
        for (columns = 0; columns < 5; columns++) {
            printf("%c     ", matrix[row][columns]);
        }
        printf("\n");
    }
}
