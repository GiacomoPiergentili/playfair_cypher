#ifndef PLAYFAIR_CYPHER_FILE_UTILS_H
#define PLAYFAIR_CYPHER_FILE_UTILS_H

#include "secretmessage_encode.h"

char *get_message(sm *message);
char *get_decoded_message(sm *message);
void create_file(sm *message, char *name);
void create_decoded_file(sm *message, char *name);
char *gen_pf_path(char *secretemessage_path, char *dir_path);
char *gen_dec_path(char *secretemessage_path, char *dir_path);

#endif //PLAYFAIR_CYPHER_FILE_UTILS_H
