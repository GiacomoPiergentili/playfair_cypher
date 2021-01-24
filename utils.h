#ifndef PLAYFAIR_CYPHER_UTILS_H
#define PLAYFAIR_CYPHER_UTILS_H

#include <stdio.h>
#include "keyfile_read.h"


typedef struct message{
    int size;
    char **pairs;
    char **encoded_pairs;
}sm;

long find_size(FILE *fp);
void read(char *buffer, FILE* file, int size);
char *read_file(FILE *fp);
char *remove_spaces(char *str);
int size_of_string(char *str);

void free_message(sm *message);


#endif //PLAYFAIR_CYPHER_UTILS_H
