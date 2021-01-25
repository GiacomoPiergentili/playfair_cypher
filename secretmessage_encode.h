#ifndef PLAYFAIR_CYPHER_SECRETMESSAGE_ENCODE_H
#define PLAYFAIR_CYPHER_SECRETMESSAGE_ENCODE_H

#include "keyfile_read.h"
#include "utils.h"

char *read_message(char *secretemessage_path, char missing_alphabet_letter, char missing_char);
sm *init_message_E(char *str);
int find_m_size(char *str);
char *remove_missing_alphabet_letter(char *str, char missing_alphabet_letter, char missing_char);
sm *create_message(char *secretemessage_path, kf *keyfile);

void fill_pairs_E(char **pairs, char *str, int size_m, char special_c);

void fill_encoded_pairs_E(char **pairs, char **encoded_pairs, char **matrix, int size_m);
void find_position(int *pos, char **matrix, char letter);
void different_r_c(char **encoded_pairs, char **matrix, int pos1[], int pos2[], int r);
void same_row(char **encoded_pairs, char **matrix, int pos1[], int pos2[], int r);
void same_column(char **encoded_pairs, char **matrix, int pos1[], int pos2[], int r);

#endif //PLAYFAIR_CYPHER_SECRETMESSAGE_ENCODE_H
