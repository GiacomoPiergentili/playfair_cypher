#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf( "NOT ENOUGH ARGUMENTS");
        exit(0);
    } else {
        process_command(argc, argv);
    }
    return 0;
}
