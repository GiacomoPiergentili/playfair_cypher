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
    char special_char;
    k *key;
}kf;



void read_all(char *keyfile_path, kf *keyfile);
void find_repetition(k *key);
void clear_alphabet(al *alphabet, k *key);

#endif //PLAYFAIR_CYPHER_KEYFILE_READ_H
