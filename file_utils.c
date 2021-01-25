#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "file_utils.h"
#include "secretmessage_encode.h"

char *get_message(sm *message) {
    char *smessage = malloc(sizeof(char) * (message->size + message->size/2));
    for (int i = 0; i < message -> size / 2; i++) {
        strcat(smessage, message -> encoded_pairs[i]);
        strcat(smessage, " ");
    }
    return smessage;
}

char *get_decoded_message(sm *message) {
    char *smessage = malloc(sizeof(char) * (message->size + message->size/2));
    for (int i = 0; i < message -> size / 2; i++) {
        strcat(smessage, message -> pairs[i]);
    }
    return smessage;
}

void create_file(sm *message, char *name) {
    FILE *fp;
    fp = fopen(name , "w");
    char *smessage = get_message(message);
    fputs(smessage, fp);
    free(smessage);
    fclose(fp);
}

void create_decoded_file(sm *message, char *name) {
    FILE *fp;
    fp = fopen(name , "w");
    char *smessage = get_decoded_message(message);
    fputs(smessage, fp);
    free(smessage);
    fclose(fp);
}

char *gen_pf_path(char *secretemessage_path, char *dir_path) {
    char *name = malloc(sizeof(char) * (strlen(dir_path) + strlen(basename(secretemessage_path) + 3)));
    strcat(name, dir_path);
    strcat(name, "/");
    strcat(name, basename(secretemessage_path));
    remove_ext(name);
    strcat(name, ".pf");
    return name;
}

char *gen_dec_path(char *secretemessage_path, char *dir_path) {
    char *name = malloc(sizeof(char) * (strlen(dir_path) + strlen(basename(secretemessage_path) + 3)));
    strcat(name, dir_path);
    strcat(name, "/");
    strcat(name, basename(secretemessage_path));
    remove_ext(name);
    strcat(name, ".dec");
    return name;
}

void remove_ext(char *name) { //https://stackoverflow.com/questions/43163677/how-do-i-strip-a-file-extension-from-a-string-in-c/43163761
    char *end = name + strlen(name);

    while (end > name && *end != '.' && *end != '\\' && *end != '/') {
        --end;
    }
    if ((end > name && *end == '.') && (*(end - 1) != '\\' && *(end - 1) != '/')) {
        *end = '\0';
    }
}