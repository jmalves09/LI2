#include <stdio.h>
#include "Carta.h"
#include "Baralho.h"
#include "Pilha.h"
#include "Jogo.h"
#include "Interface.h"

#define NUM_PILHAS 7
#define TAM_PILHA 5


int main() {
    /* Criar cartas
    Carta c1 = criar_carta('A', 'S'); // Ás de Espadas
    Carta c2 = criar_carta('K', 'S'); // Rei de Espadas
    Carta c3 = criar_carta('Q', 'H'); // 10 de Copas

    // Imprimir cartas
    printf("Cartas:\n");
    imprimir_carta(c1);
    imprimir_carta(c2);
    imprimir_carta(c3);

    // Valores numéricos
    printf("\nValores:\n");
    printf("%c%c -> %d\n", c1.valor, c1.naipe, valor_numerico(c1));
    printf("%c%c -> %d\n", c2.valor, c2.naipe, valor_numerico(c2));
    printf("%c%c -> %d\n", c3.valor, c3.naipe, valor_numerico(c3));

    // Testar jogadas válidas
    printf("\nJogadas válidas:\n");
    printf("c1 e c2: %d\n", jogada_valida(c1, c2)); // A vs K
    printf("c2 e c3: %d\n", jogada_valida(c2, c3)); // K vs 10

    */
    /*
    Baralho b;

    iniciar_baralho(&b);
    b.topo = 0;

    printf("Baralho inicial:\n");
    for(int i=0; i<TAM_BARALHO; i++) {
        imprimir_carta(b.cartas[i]);
    }


    baralhar(&b);
    b.topo = 0;

    printf("\nBaralho baralhado:\n");
    for(int i=0; i<TAM_BARALHO; i++) {
        imprimir_carta(b.cartas[i]);
    }

    // Tirar varias cartas
    printf("\nTirando 5 cartas do topo:\n");
    for(int i=0; i<5; i++) {
        Carta c = tirar_carta(&b);
        imprimir_carta(c);
    }

    printf("\nBaralho vazio? %d\n", baralho_vazio(&b));
    */
    /*
    Baralho b;
    Pilha pilhas[NUM_PILHAS];
    iniciar_baralho(&b);
    baralhar(&b);

    for(int i=0; i<NUM_PILHAS; i++)
        iniciar_pilha(&pilhas[i]);

    for(int i=0; i<NUM_PILHAS; i++){
        for(int j=0; j<TAM_PILHA; j++){
            adiciona_carta(&pilhas[i], tirar_carta(&b));
        }
    }

    for(int i=0; i<NUM_PILHAS; i++){
        printf("Pilha %d: ", i+1);
        for(int j=0; j<pilhas[i].topo; j++){
            imprimir_carta(pilhas[i].cartas[j]);
        }
        printf("\n");
    }

    printf("\nCartas restantes no baralho: %d\n", TAM_BARALHO - b.topo);
    */
    /*
    Jogo jogo;

    iniciar_jogo(&jogo);
    mostrar_jogo(&jogo);

    printf("\nTirei do uma carta do baralho...\n");
    tirar_baralho(&jogo);
    mostrar_jogo(&jogo);
*/
/*
 char input[10];
    int comando;

    comando = ler_comando(input);

    if(comando == 2) {
        printf("Escolheste tirar do baralho\n");
    } else if(comando == 1) {
        printf("Escreveste a carta: %s\n", input);
    }
*/
    return 0;
}
