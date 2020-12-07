#include <stdio.h>
#include "stdlib.h"
#include "secretmessage_encode.h"
#include "utils.h"
#include "matrix_gen.h"

char *read_message(char *secretemessage_path) {
    FILE *smp = fopen(secretemessage_path, "r");
    char *str = read_file(smp);
    return remove_spaces(str);
}

void create_message(/*char *secretemessage_path*/) {
    //char *str = read_message(secretemessage_path);
    sm *message = malloc(sizeof(sm) + 1);
    message -> size = size_of_string("CIAOOOOO");
    int i;
    message -> pairs = (char **) calloc(message -> size/2, sizeof(char *));
    for (i = 0; i < 2 ; i++) {
        message -> pairs[i] = (char *) calloc(2, sizeof(char));
    }
    int row, columns;
    for (row=0; row<message ->size/2; row++)
    {
        for(columns=0; columns<2; columns++)
        {
            int x = 5;
            printf("%d", x*=3+7);
            printf("%d     ", message->pairs[row][columns]);
        }
        printf("\n");
    }

}