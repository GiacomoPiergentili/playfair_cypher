#ifndef PLAYFAIR_CYPHER_UTILS_H
#define PLAYFAIR_CYPHER_UTILS_H

#include <stdio.h>
#include "keyfile_read.h"

long find_size(FILE *fp);
void read(char *buffer, FILE* file, int size);
char *read_file(FILE *fp);
char *remove_spaces(char *str);
void check_exist(FILE *fp, char *message);

#endif //PLAYFAIR_CYPHER_UTILS_H
