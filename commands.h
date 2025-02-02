#ifndef PLAYFAIR_CYPHER_COMMANDS_H
#define PLAYFAIR_CYPHER_COMMANDS_H

#include "keyfile_read.h"

void process_command(int argc, char *argv[]);
void encode(kf *keyfile, char *secretemessage_path, char *dir_path);
void decode(kf *keyfile, char *encodedmessage_path, char *dir_path);

#endif //PLAYFAIR_CYPHER_COMMANDS_H
