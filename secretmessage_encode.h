#ifndef PLAYFAIR_CYPHER_SECRETMESSAGE_ENCODE_H
#define PLAYFAIR_CYPHER_SECRETMESSAGE_ENCODE_H

typedef struct message{
    int size;
    char **pairs;
    char **encoded_pairs;
}sm;

char *read_message(char *secretemessage_path);
void create_message(char *secretemessage_path);
void fill(char **matrix, char *str, int size_m, char special_c);
int find_m_size(char *str);

#endif //PLAYFAIR_CYPHER_SECRETMESSAGE_ENCODE_H
