#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <dirent.h>
#include <errno.h>
#include "file_utils.h"

char *get_message(sm *message) {
    char *smessage = malloc(sizeof(char) * (message->size + message->size/2) + 1);
    strcpy(smessage,"");
    for (int i = 0; i < message -> size / 2; i++) {
        strcat(smessage, message -> encoded_pairs[i]);
        strcat(smessage, " ");
    }
    return smessage;
}

char *get_decoded_message(sm *message) {
    char *smessage = malloc(sizeof(char) * (message->size + message->size/2) + 1);
    strcpy(smessage,"");
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
    char *name = malloc(sizeof(char) * (strlen(dir_path) + strlen(basename(secretemessage_path) + 4)));
    strcpy(name, dir_path);
    strcat(name, "/");
    strcat(name, basename(secretemessage_path));
    remove_ext(name);
    strcat(name, ".pf");
    return name;
}

char *gen_dec_path(char *secretemessage_path, char *dir_path) {
    char *name = malloc(sizeof(char) * (strlen(dir_path) + strlen(basename(secretemessage_path) + 5)));
    strcpy(name, dir_path);
    strcat(name, "/");
    strcat(name, basename(secretemessage_path));
    remove_ext(name);
    strcat(name, ".dec");
    return name;
}

void remove_ext(char *name) {
    char *end = name + strlen(name);
    while (end > name && *end != '.' && *end != '\\' && *end != '/') {
        --end;
    }
    if ((end > name && *end == '.') && (*(end - 1) != '\\' && *(end - 1) != '/')) {
        *end = '\0';
    }
}

void check_dir(char *dir_path) {
    DIR* dir = opendir(dir_path);
    if (ENOENT == errno) {
        printf("DIRECTORY NOT FOUND");
        exit(1);
    }
    closedir(dir);
}