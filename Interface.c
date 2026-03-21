#include <stdio.h>
#include <string.h>
#include "Interface.h"



int ler_comando(char *input) {
    printf("\nEscreve uma carta ou B para baralho: ");
    scanf("%s", input);

    if(strcmp(input, "B") == 0 || strcmp(input, "b") == 0) {
        return 2;
    } 
    if (strcmp(input, "X") == 0 || strcmp(input, "x") == 0){
        return 0;
    }
        return 1;
}