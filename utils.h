#ifndef PLAYFAIR_CYPHER_UTILS_H
#define PLAYFAIR_CYPHER_UTILS_H

#include "keyfile_read.h"

long find_size(FILE *fp);
void read(char *buffer, FILE* file, int size);
char *read_file(FILE *fp);
char *remove_spaces(char *str);
int size_of_string(char *str);


#endif //PLAYFAIR_CYPHER_UTILS_H
