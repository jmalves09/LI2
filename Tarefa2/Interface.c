#include <stdio.h>
#include <string.h>
#include "Interface.h"



int ler_comando(char *input) {
    printf("\nEscreve o numero da pilha, H para ajuda ou X para sair: ");
    scanf("%s", input);

    if(strcmp(input, "X") == 0 || strcmp(input, "x") == 0) {
        return 0;
    }

    if(strcmp(input, "H") == 0 || strcmp(input, "h") == 0) {
        return 2;
    }

    return 1;
}