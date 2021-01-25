#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("%s", "NOT ENOUGH ARGUMENTS");
        exit(0);
    } else {
        process_command(argc, argv);
    }
}
