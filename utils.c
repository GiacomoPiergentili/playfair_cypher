#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"
#include "matrix_utils.h"

long find_size(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long int res = ftell(fp);
    rewind(fp);
    return res;
}

void read(char *buffer, FILE *fp, int size) {
    int i;
    char ch;
    for (i = 0; (i < size - 1); i++) {
        ch = fgetc(fp);
        buffer[i] = toupper(ch);
    }
    buffer[i] = '\0';
}

char *read_file(FILE *fp) {
    long int size = find_size(fp);
    char *buffer = malloc(size + 1);
    read(buffer, fp, size);
    return buffer;
}

char *remove_spaces(char *str) {
    char *out = str, *put = str;
    for (; *str != '\0'; ++str) {
        if (*str != ' ')
            *put++ = *str;
    }
    *put = '\0';
    return out;
}

int size_of_string(char *str) {
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}

void free_message(sm *message) {
    free_matrix(message->pairs, message->size/2);
    message->pairs = NULL;
    free_matrix(message->encoded_pairs, message->size/2);
    message->encoded_pairs = NULL;
    free(message);
    message = NULL;
}
