#ifndef PLAYFAIR_CYPHER_SECRETMESSAGE_DECODE_H
#define PLAYFAIR_CYPHER_SECRETMESSAGE_DECODE_H

char *read_encoded_message(char *encodedmessage_path);
sm *create_encoded_message(char *encodedmessage_path, kf *keyfile);
sm *init_message_D(char *str);

void fill_encoded_pairs_D(int size, char *str, char **encoded_pairs, char missing_alphabet_letter);

void fill_pairs_D (char **pairs, char **encoded_pairs, char **matrix, int size);
void different_r_c_D(char **pairs, char **matrix, int pos1[], int pos2[], int r);
void same_row_D(char **pairs, char **matrix, int pos1[], int pos2[], int r);
void same_column_D(char **pairs, char **matrix, int pos1[], int pos2[], int r);



void check_odd (char *str);


#endif //PLAYFAIR_CYPHER_SECRETMESSAGE_DECODE_H
