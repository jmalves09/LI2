#include <stdio.h>
#include "Jogo.h"

void iniciar_jogo(Jogo *j) {
    int dist[NUM_PILHAS] = {8, 8, 8, 7, 6, 5, 4, 3, 2, 1};

    iniciar_baralho(&j->baralho);
    baralhar(&j->baralho);
    j->completas = 0;

    for(int i = 0; i < NUM_PILHAS; i++) {
        iniciar_pilha(&j->pilhas[i]);
    }

    for(int i = 0; i < NUM_PILHAS; i++) {
        for(int c = 0; c < dist[i]; c++) {
            adiciona_carta(&j->pilhas[i], tirar_carta(&j->baralho));
        }
    }
}
int verifica_sequencia(Jogo *j, int origem, int n) {
 return encontrar_destino(j, origem, n) != -1;
}

int existe_jogada_possivel(Jogo *j) {
    for(int i = 0; i < NUM_PILHAS; i++) {
        Pilha *p = &j->pilhas[i];

        if(!pilha_vazia(p)) {
            for(int n = p->topo; n >= 1; n--) {
                int pos = p->topo - n;

                if(n == 1 || contar_sequencia(p, pos) >= n) {
                    if(verifica_sequencia(j, i, n)) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

void sequencia_completa(Jogo *j, int pilha) {
    Pilha *p = &j->pilhas[pilha];

    if(p->topo < 13) {
        return;
    }

    int pos = p->topo - 13;

    if(contar_sequencia(p, pos) >= 13) {
        remover_n_cartas(p, 13);
        j->completas++;
    }
}

int encontrar_destino(Jogo *j, int origem, int n) {
    int pos = j->pilhas[origem].topo - n;
    Carta base = ver_carta(&j->pilhas[origem], pos);

    for(int d = 0; d < NUM_PILHAS; d++) {
        if(d != origem) {
            if(pilha_vazia(&j->pilhas[d])) {
                return d;
            }

            if(valor_numerico(base) == valor_numerico(ver_topo(&j->pilhas[d])) - 1) {
                return d;
            }
        }
    }

    return -1;
}

int mover_cartas(Jogo *j, int origem) {
  Pilha *p = &j->pilhas[origem];

    if(origem < 0 || origem >= NUM_PILHAS) {
        return 0;
    }

    if(pilha_vazia(p)) {
        return 0;
    }

    for(int n = p->topo; n >= 1; n--) {
        int pos = p->topo - n;

        if(n == 1 || contar_sequencia(p, pos) >= n) {
            int destino = encontrar_destino(j, origem, n);

            if(destino != -1) {
                Carta bloco[13];

                for(int i = 0; i < n; i++) {
                    bloco[i] = ver_carta(p, pos + i);
                }

                adicionar_n_cartas(&j->pilhas[destino], bloco, n);
                remover_n_cartas(p, n);
                sequencia_completa(j, destino);
                return 1;
            }
        }
    }

    return 0;
    
}

void mostrar_jogo(Jogo *j) {
    for(int i = 0; i < NUM_PILHAS; i++) {
        printf("Pilha %d: ", i + 1);

        for(int c = 0; c < j->pilhas[i].topo; c++) {
            imprimir_carta(j->pilhas[i].cartas[c]);
        }

        printf("\n");
    }

    printf("Sequencias completas: %d\n", j->completas);
}

int jogo_terminou(Jogo *j) {
    if(j->completas == 4) {
        return 1;
    }

    if(!existe_jogada_possivel(j)) {
        return 1;
    }

    return 0;
}