#include <stdlib.h>

#include "commands.h"
#include "matrix_gen.h"
#include "secretmessage_encode.h"
#include "secretmessage_decode.h"
#include "file_utils.h"


void encode(kf *keyfile, char *secretemessage_path, char *dir_path) {
    char *name = gen_pf_path(secretemessage_path, dir_path);
    sm *message = create_message(secretemessage_path, keyfile);
    create_file(message, name);
    free(message);
    free(name);
}

void decode(kf *keyfile, char *encodedmessage_path, char *dir_path) {
    char *name = gen_dec_path(encodedmessage_path, dir_path);
    sm *message = create_encoded_message(encodedmessage_path, keyfile);
    create_decoded_file(message, name);
    free(message);
    free(name);
}

kf *gen_kf(char *kf_path) {
    return complete_keyfile(kf_path);
}

