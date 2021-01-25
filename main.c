#include <stdio.h>
#include <string.h>
#include "commands.h"

int main(int argc, char *argv[]) {
    kf *keyfile = gen_kf(argv[2]);
    if (strcmp(argv[1], "encode") == 0) {
        for (int i = 4; i < argc; i++) {
            encode(keyfile, argv[i], argv[3]);
        }
    } else if (strcmp(argv[1], "decode") == 0) {
        for (int i = 4; i < argc; i++) {
            decode(keyfile, argv[i], argv[3]);
        }
    }
    else
        printf("%s", "UNKNOWN COMMAND");
    free_keyfile(keyfile);
}
