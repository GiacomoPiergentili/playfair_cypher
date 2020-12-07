#include <stdio.h>
#include "stdlib.h"
#include "utils.h"
#include "keyfile_read.h"
#include "matrix_gen.h"
#include "secretmessage_encode.h"

int main(int argc, char* argv[]) {
    run1(argv[1]);
    create_message();
}
