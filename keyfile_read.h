#ifndef PLAYFAIR_CYPHER_KEYFILE_READ_H
#define PLAYFAIR_CYPHER_KEYFILE_READ_H

typedef struct s_alphabet {
    char *alphabet;
    int *flag;
}al;

typedef struct key {
    char *key;
    int size;
    int *flag;
}k;

typedef struct keyfile {
    al *alphabet;
    char missing_char;
    char missing_alphabet_letter;
    char special_char;
    k *key;
    char **matrix;
}kf;



void read_all(char *keyfile_path, kf *keyfile);
void find_repetition(k *key);
void clear_alphabet(al *alphabet, k *key);
char find_missing_letter(al *alphabet);

#endif //PLAYFAIR_CYPHER_KEYFILE_READ_H
