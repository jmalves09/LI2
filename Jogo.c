#include <stdio.h>
#include "Jogo.h"


void iniciar_jogo(Jogo *j){

    iniciar_baralho(&j->baralho);
    baralhar(&j->baralho);

    for(int i = 0; i < NUM_PILHAS; i++) {
        iniciar_pilha(&j->pilhas[i]);
    }

    for(int i = 0; i < NUM_PILHAS; i++) {
        for(int c = 0; c < TAM_PILHA; c++) {
            adiciona_carta(&j->pilhas[i], tirar_carta(&j->baralho));
        }
    }

    Carta topo = tirar_carta(&j->baralho);
    adiciona_carta(&j->descarte, topo);
}

int jogar_carta(Jogo *j, Carta c) {

    for(int i = 0; i < NUM_PILHAS; i++) {

        Pilha *p = &j->pilhas[i];

        if(!pilha_vazia(p)) {

            Carta topo = ver_topo(p);

            if(get_valor(topo) == get_valor(c) &&
               get_naipe(topo) == get_naipe(c)) {

                Carta removida = remove_Carta(p);
                adiciona_carta(&j->descarte, removida);

                return 1;
            }
        }
    }

    printf("Jogada inválida\n");
    return 0;
}

void tirar_baralho(Jogo *j){
if(baralho_vazio(&j->baralho)) {
        printf("Baralho vazio!\n");
    }
Carta c = tirar_carta(&j->baralho);
    adiciona_carta(&j->descarte, c);
}   

int pilhas_vazias(Jogo *j) {
    for (int i = 0; i < NUM_PILHAS; i++) {
        if (!pilha_vazia(&j->pilhas[i])) {
            return 0;
        }
    }
    return 1;
}

int existe_jogada_possivel(Jogo *j) {
    if (!baralho_vazio(&j->baralho)) return 1;

    Carta topo_descarte = ver_topo(&j->descarte);

    for (int i = 0; i < NUM_PILHAS; i++) {
        Pilha *p = &j->pilhas[i];

        if (!pilha_vazia(p)) {
            Carta topo_pilha = ver_topo(p);

            if (jogada_valida(topo_pilha, topo_descarte)) {
                return 1;
            }
        }
    }
    return 0;
}

int jogo_terminou(Jogo *j) {
    if (pilhas_vazias(j)) return 1;

    if (!existe_jogada_possivel(j)) return 1;

    return 0;
}

void mostrar_jogo(Jogo *j) {

    for (int i = 0; i < NUM_PILHAS; i++) {
        printf("Pilha %d: ", i + 1);

        for (int c = 0; c < j->pilhas[i].topo; c++) {
            imprimir_carta(j->pilhas[i].cartas[c]);
        }

        printf("\n");
    }

    if (!pilha_vazia(&j->descarte)) {
        printf("Descarte: ");
        imprimir_carta(ver_topo(&j->descarte));
        printf("\n");
    } else {
        printf("Descarte vazio!\n");
    }
}