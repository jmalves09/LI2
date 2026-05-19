/* src/Jogo.c */

#include <stdio.h>
#include <string.h>

#include "Jogo.h"
#include "Parser.h"


void iniciarJogo(Jogo *j, const char *ficheiroDsl) {

    inicializaDsl(&j->regras);

    parseFicheiro(ficheiroDsl, &j->regras);

    iniciar_baralho(&j->baralho);

    baralhar(&j->baralho);

    j->numPilhas = 0;

    criarPilhas(j);

    distribuirCartas(j);
}


void criarPilhas(Jogo *j) {

    int i;
    int n;

    for(i = 0; i < j->regras.numInits; i++) {

        InitPilha init;

        init = j->regras.inits[i];

        for(n = 0; n < init.quantidade; n++) {

            PilhaJogo *p;

            p = &j->pilhas[j->numPilhas];

            sprintf(p->nome,
                    "%s%d",
                    init.tipo,
                    n + 1);

            strcpy(p->tipo,
                   init.tipo);

            iniciar_pilha(&p->pilha);

            j->numPilhas++;
        }
    }
}

void distribuirCartas(Jogo *j) {

    int i;

    for(i = 0; i < j->numPilhas; i++) {

        if(strcmp(j->pilhas[i].tipo,
                  "TAB") == 0) {

            adiciona_carta(&j->pilhas[i].pilha,
                            tirar_carta(&j->baralho));
        }
    }
}

RegraMovimento *encontrarMovimento(Jogo *j,
                                   int origem,
                                   int destino) {

    int i;

    char *tipoOrigem;
    char *tipoDestino;

    tipoOrigem = j->pilhas[origem].tipo;
    tipoDestino = j->pilhas[destino].tipo;

    for(i = 0; i < j->regras.numMovimentos; i++) {

        RegraMovimento *m;

        m = &j->regras.movimentos[i];

        if(strcmp(m->origem,
                  tipoOrigem) == 0 &&

           strcmp(m->destino,
                  tipoDestino) == 0) {

            return m;
        }
    }

    return NULL;
}

int encontrarTipo(Dsl *dsl,
                  const char *tipo) {

    int i;

    for(i = 0; i < dsl->numTipos; i++) {

        if(strcmp(dsl->tipos[i].nome,
                  tipo) == 0) {

            return i;
        }
    }

    return -1;
}

int sequenciaValida(Pilha *p,
                    int pos,
                    int quantidade,
                    int mesmoNaipe) {

    int i;

    for(i = pos; i < pos + quantidade - 1; i++) {

        Carta atual;
        Carta seguinte;

        atual = ver_carta(p,
                          i);

        seguinte = ver_carta(p,
                             i + 1);

        if(valor_numerico(atual) !=
           valor_numerico(seguinte) + 1) {

            return 0;
        }

        if(mesmoNaipe) {

            if(get_naipe(atual) !=
               get_naipe(seguinte)) {

                return 0;
            }
        }
    }

    return 1;
}

int pilhaAceitaCarta(Jogo *j,
                     int origem,
                     int destino,
                     int quantidade) {

    RegraMovimento *m;

    Pilha *pOrigem;
    Pilha *pDestino;

    Carta cartaOrigem;
    Carta cartaDestino;

    int pos;
    int mesmoNaipe;

    m = encontrarMovimento(j,
                           origem,
                           destino);

    if(m == NULL) {
        return 0;
    }

    pOrigem = &j->pilhas[origem].pilha;
    pDestino = &j->pilhas[destino].pilha;

    if(pilha_vazia(pOrigem)) {
        return 0;
    }


    /* regra '-' */

    if(temFlag(m->flags,
               '-') &&

       quantidade != 1) {

        return 0;
    }


    /* regra '+' */

    if(temFlag(m->flags,
               '+')) {

        pos = pOrigem->topo - quantidade;

        mesmoNaipe = temFlag(m->flags,
                             'm');

        if(!sequenciaValida(pOrigem,
                            pos,
                            quantidade,
                            mesmoNaipe)) {

            return 0;
        }
    }


    cartaOrigem = ver_carta(pOrigem,
                            pOrigem->topo - quantidade);


    /* regra 'v' */

    if(pilha_vazia(pDestino)) {

        if(temFlag(m->flags,
                   'v')) {

            return 1;
        }

        return 0;
    }


    cartaDestino = ver_topo(pDestino);


    /* regra '<' */

    if(temFlag(m->flags,
               '<')) {

        if(valor_numerico(cartaOrigem) !=
           valor_numerico(cartaDestino) - 1) {

            return 0;
        }
    }


    /* regra '>' */

    if(temFlag(m->flags,
               '>')) {

        if(valor_numerico(cartaOrigem) !=
           valor_numerico(cartaDestino) + 1) {

            return 0;
        }
    }


    /* regra 's' */

    if(temFlag(m->flags,
               's')) {

        if(get_naipe(cartaOrigem) !=
           get_naipe(cartaDestino)) {

            return 0;
        }
    }

    return 1;
}

int maiorSequenciaMovivel(Jogo *j,
                          int origem,
                          int destino) {

    RegraMovimento *m;

    Pilha *p;

    int n;
    int pos;
    int mesmoNaipe;

    m = encontrarMovimento(j,
                           origem,
                           destino);

    if(m == NULL) {
        return 0;
    }

    p = &j->pilhas[origem].pilha;

    mesmoNaipe = temFlag(m->flags,
                         'm');

    for(n = p->topo; n >= 1; n--) {

        pos = p->topo - n;

        if(sequenciaValida(p,
                           pos,
                           n,
                           mesmoNaipe)) {

            if(pilhaAceitaCarta(j,
                                origem,
                                destino,
                                n)) {

                return n;
            }
        }
    }

    return 0;
}

int moverCartas(Jogo *j,
                int origem,
                int destino) {

    Carta bloco[52];

    Pilha *pOrigem;
    Pilha *pDestino;

    int quantidade;
    int pos;
    int i;

    if(origem < 0 ||
       origem >= j->numPilhas) {

        return 0;
    }

    if(destino < 0 ||
       destino >= j->numPilhas) {

        return 0;
    }

    if(origem == destino) {
        return 0;
    }

    pOrigem = &j->pilhas[origem].pilha;
    pDestino = &j->pilhas[destino].pilha;

    if(pilha_vazia(pOrigem)) {
        return 0;
    }

    quantidade = maiorSequenciaMovivel(j,
                                       origem,
                                       destino);

    if(quantidade == 0) {
        return 0;
    }

    pos = pOrigem->topo - quantidade;

    for(i = 0; i < quantidade; i++) {

        bloco[i] = ver_carta(pOrigem,
                             pos + i);
    }

    adicionar_n_cartas(pDestino,
                       bloco,
                       quantidade);

    remover_n_cartas(pOrigem,
                      quantidade);

    return 1;
}

int executarAuto(Jogo *j) {

    int r;
    int o;
    int d;

    for(r = 0; r < j->regras.numAutos; r++) {

        RegraMovimento *a;

        a = &j->regras.autos[r];

        for(o = 0; o < j->numPilhas; o++) {

            for(d = 0; d < j->numPilhas; d++) {

                if(o != d) {

                    if(strcmp(j->pilhas[o].tipo,
                              a->origem) == 0 &&

                       strcmp(j->pilhas[d].tipo,
                              a->destino) == 0) {

                        if(maiorSequenciaMovivel(j,
                                                 o,
                                                 d) > 0) {

                            moverCartas(j,
                                        o,
                                        d);

                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int verificarWin(Jogo *j) {

    int w;
    int p;

    for(w = 0; w < j->regras.numWins; w++) {

        RegraWin *win;

        win = &j->regras.wins[w];

        for(p = 0; p < j->numPilhas; p++) {

            if(strcmp(j->pilhas[p].tipo,
                      win->tipo) == 0) {

                if(j->pilhas[p].pilha.topo !=
                   win->objetivo) {

                    return 0;
                }
            }
        }
    }

    return 1;
}

int jogoTerminou(Jogo *j) {
return verificarWin(j);
}


void mostrarJogo(Jogo *j) {
 int i;
    int c;

    printf("JOGO: %s\n\n",
           j->regras.nomeJogo);

    for(i = 0; i < j->numPilhas; i++) {

        printf("%s: ",
               j->pilhas[i].nome);

        for(c = 0;
            c < j->pilhas[i].pilha.topo;
            c++) {

            imprimir_carta(j->pilhas[i].pilha.cartas[c]);
        }

        printf("\n");
    }
}

