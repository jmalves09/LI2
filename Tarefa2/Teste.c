#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Carta.h"
#include "Pilha.h"
#include "Baralho.h"
#include "Jogo.h"

int main(){
    // Criar cartas
    Carta c1 = criar_carta('A', 'S'); // Ás de Espadas
    Carta c2 = criar_carta('2', 'S'); // dois de Espadas
    Carta c3 = criar_carta('3', 'O'); // dois de Ouros

    // Valores numéricos
    printf("\nValores:\n");
    printf("c1 = %c%c -> %d\n", c1.valor, c1.naipe, valor_numerico(c1));
    printf("c2 = %c%c -> %d\n", c2.valor, c2.naipe, valor_numerico(c2));
    printf("c3 = %c%c -> %d\n", c3.valor, c3.naipe, valor_numerico(c3));

    printf("\n testar pode_mover:\n");
    printf("c1 e c2: %d\n", pode_mover(c1, c2));
    printf("c1 e c3: %d\n", pode_mover(c1, c3));

    printf("\n testar sequencia_valida:\n");
    printf("c1 e c2: %d\n", sequencia_valida(c1, c2));
    printf("c1 e c3: %d\n", sequencia_valida(c1, c3));

    Pilha p;
    Carta cartas[3];

    iniciar_pilha(&p);

    adiciona_carta(&p, criar_carta('K', 'S'));
    adiciona_carta(&p, criar_carta('Q', 'S'));
    adiciona_carta(&p, criar_carta('J', 'S'));
    adiciona_carta(&p, criar_carta('T', 'H'));

    printf("Topo: ");
    imprimir_carta(ver_topo(&p));
    printf("\n");

    printf("Carta na posicao 1: ");
    imprimir_carta(ver_carta(&p, 1));
    printf("\n");

    printf("Sequencia desde pos 0: %d\n", contar_sequencia(&p, 0));
    printf("Sequencia desde pos 2: %d\n", contar_sequencia(&p, 2));

    cartas[0] = criar_carta('9', 'H');
    cartas[1] = criar_carta('8', 'H');
    cartas[2] = criar_carta('7', 'H');

    adicionar_n_cartas(&p, cartas, 3);

    printf("Depois de adicionar 3 cartas, topo: ");
    imprimir_carta(ver_topo(&p));
    printf("\n");

    remover_n_cartas(&p, 2);

    printf("Depois de remover 2 cartas, topo: ");
    imprimir_carta(ver_topo(&p));
    printf("\n");

    printf("Topo da pilha agora: %d\n", p.topo);

    Baralho b;

    srand(time(NULL));

    iniciar_baralho(&b);

    printf("Baralho inicial:\n");
    for(int i = 0; i < TAM_BARALHO; i++) {
        imprimir_carta(b.cartas[i]);
    }
    printf("\n");

    baralhar(&b);

    printf("\nBaralho baralhado:\n");
    for(int i = 0; i < TAM_BARALHO; i++) {
        imprimir_carta(b.cartas[i]);
    }
    printf("\n");

    printf("\nA tirar 5 cartas:\n");
    for(int i = 0; i < 5; i++) {
        Carta c = tirar_carta(&b);
        imprimir_carta(c);
    }
    printf("\n");

    printf("Topo depois de tirar 5 cartas: %d\n", b.topo);
    printf("Baralho vazio? %d\n", baralho_vazio(&b));
    printf("Baralho vazio no fim? %d\n", baralho_vazio(&b));

    Jogo j;

    srand(time(NULL));

    iniciar_jogo(&j);

    printf("=== JOGO INICIAL ===\n");
    mostrar_jogo(&j);

    printf("\nCompletas: %d\n", j.completas);
    printf("Existe jogada possivel? %d\n", existe_jogada_possivel(&j));

    printf("\nA tentar mover da pilha 1...\n");
    printf("Resultado: %d\n", mover_cartas(&j, 0));

    printf("\n=== JOGO DEPOIS DA JOGADA ===\n");
    mostrar_jogo(&j);

    printf("\nJogo terminou? %d\n", jogo_terminou(&j));

    return 0;


    return 0;
}