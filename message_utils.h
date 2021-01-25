#ifndef PLAYFAIR_CYPHER_MESSAGE_UTILS_H
#define PLAYFAIR_CYPHER_MESSAGE_UTILS_H

typedef struct message{
    int size;
    char **pairs;
    char **encoded_pairs;
}sm;

int find_m_size(char *str);
char *remove_missing_alphabet_letter(char *str, char missing_alphabet_letter, char missing_char);
void free_message(sm *message);

#endif //PLAYFAIR_CYPHER_MESSAGE_UTILS_H
