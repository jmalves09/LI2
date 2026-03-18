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

int jogar_carta(Jogo *j, Carta c){

    Carta topo_descarte = ver_topo(&j->descarte);

    for(int i = 0; i < NUM_PILHAS; i++) {
        Pilha *p = &j->pilhas[i];

        if (!pilha_vazia(p)) {  
            Carta topo_pilha = ver_topo(p);

            if (jogada_valida(c, topo_descarte)) {
                remove_Carta(p);
                adiciona_carta(&j->descarte, c);
                imprimir_carta(c);
                return 1;
            }
        }
    }
    printf("Carta inválida: ");
    imprimir_carta(c);
    return 0;
}

void tirar_baralho(Jogo *j){
if(baralho_vazio(&j->baralho)) {
        printf("Baralho vazio!\n");
    }
Carta c = tirar_carta(&j->baralho);
    adiciona_carta(&j->descarte, c);
    imprimir_carta(c);
}   

int jogo_terminou(Jogo *j){
    int todas_vazias = 1;
    for(int i = 0; i < NUM_PILHAS; i++) {
        if(!pilha_vazia(&j->pilhas[i])) {
            todas_vazias = 0; 
        }
    }
    if(todas_vazias) return 1;

    if(baralho_vazio(&j->baralho)) {
        Carta topo_descarte = ver_topo(&j->descarte);
        int jogada_possivel = 0;

        for(int i = 0; i < NUM_PILHAS; i++) {
            Pilha *p = &j->pilhas[i];
            if(!pilha_vazia(p)) {
                Carta topo_pilha = ver_topo(p);
                if(jogada_valida(topo_pilha, topo_descarte)) {
                    jogada_possivel = 1;
                }
            }
        }
        if ( jogada_possivel==0) return 1;
    }
    return 0;
}

void mostrar_jogo(Jogo *j) {

    for(int i = 0; i < NUM_PILHAS; i++) {
        printf("Pilha %d: ", i+1);
        for(int c = 0; c < j->pilhas[i].topo; c++) {
            imprimir_carta(j->pilhas[i].cartas[c]);
        }
        printf("\n");
    }

    if(!pilha_vazia(&j->descarte)) {
        imprimir_carta(ver_topo(&j->descarte));
    } else {
        printf("Descarte vazio!\n");
    }
}