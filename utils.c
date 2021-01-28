#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include "utils.h"

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

void check_exist(FILE *fp, char *message) {
    if (fp == NULL) {
        char *str = malloc(sizeof(char) * (strlen(message) + 10));
        strcpy(str, message);
        strcat(str, " ");
        strcat(str, "NOT FOUND");
        printf("%s", str);
        free(str);
        exit(1);
    }
}
