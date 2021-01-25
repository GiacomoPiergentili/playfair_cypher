#include <stdlib.h>
#include <stdio.h>
#include "matrix_utils.h"


char **initialize_matrix(char **matrix, int nr, int nc) {
    int i;
    matrix = (char **) calloc(nr, sizeof(char *));
    for (i = 0; i < nr; i++) {
        matrix[i] = (char *) calloc(nc, sizeof(char));
    }
    return matrix;
}

void free_matrix(char **matrix, int nr) {
    if (matrix != NULL) {
        for (int i = 0; i < nr; ++i) {
            free(matrix[i]);
            matrix[i] = NULL;
        }
        free(matrix);
        matrix = NULL;
    }
}

void print_matrix(char **matrix, int nr, int nc) {
    int row, columns;
    for (row = 0; row < nr; row++) {
        for (columns = 0; columns < nc; columns++) {
            printf("%c     ", matrix[row][columns]);
        }
        printf("\n");
    }
}
