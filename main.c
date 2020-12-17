#include "matrix_gen.h"
#include "secretmessage_encode.h"
#include "secretmessage_decode.h"

int main(int argc, char* argv[]) {
    kf *keyfile = run1(argv[1]);
    create_message(argv[2], keyfile);
    create_encoded_message(argv[3], keyfile);
}
