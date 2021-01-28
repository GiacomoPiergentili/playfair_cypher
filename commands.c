#include <stdlib.h>
#include <memory.h>
#include "commands.h"
#include "keyfile_gen.h"
#include "secretmessage_encode.h"
#include "secretmessage_decode.h"
#include "file_utils.h"
#include "utils.h"

void process_command(int argc, char *argv[]) {
    kf *keyfile = complete_keyfile(argv[2]);
    if (strcmp(argv[1], "encode") == 0) {
        for (int i = 4; i < argc; i++) {
            encode(keyfile, argv[i], argv[3]);
        }
    } else if (strcmp(argv[1], "decode") == 0) {
        for (int i = 4; i < argc; i++) {
            decode(keyfile, argv[i], argv[3]);
        }
    }
    else {
        printf("UNKNOWN COMMAND");
        exit(1);
    }
    free_keyfile(keyfile);
}

void encode(kf *keyfile, char *secretemessage_path, char *dir_path) {
    check_dir(dir_path);
    char *name = gen_pf_path(secretemessage_path, dir_path);
    sm *message = create_message(secretemessage_path, keyfile);
    create_file(message, name);
    free_message(message);
    free(name);
}

void decode(kf *keyfile, char *encodedmessage_path, char *dir_path) {
    check_dir(dir_path);
    char *name = gen_dec_path(encodedmessage_path, dir_path);
    sm *message = create_encoded_message(encodedmessage_path, keyfile);
    create_decoded_file(message, name);
    free_message(message);
    free(name);
}

