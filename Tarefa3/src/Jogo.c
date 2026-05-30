/* src/Jogo.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "Jogo.h"
#include "Parser.h"


void iniciarJogo(Jogo *j, const char *ficheiroDsl) {

    inicializaDsl(&j->regras);

    parseFicheiro(ficheiroDsl, &j->regras);

    iniciar_baralho(&j->baralho);

    baralhar(&j->baralho);

    j->numPilhas = 0;

    criarPilhas(j);

    j->existeUndo = 0;
}

void criarPilhas(Jogo *j) {

int i;

int tab = 1;
int fund = 1;
int stock = 1;
int descarte = 1;
int cell = 1;

for(i = 0; i < j->regras.numInits; i++) {

    InitPilha init;

    PilhaJogo *p;

    int c;
    int t;

    init = j->regras.inits[i];

    p = &j->pilhas[j->numPilhas];

    if(strcmp(init.tipo, "TAB") == 0) {

        snprintf(p->nome, sizeof(p->nome), "TAB%d", tab);

        tab++;
    }

    else if(strcmp(init.tipo, "FUND") == 0) {

        snprintf(p->nome, sizeof(p->nome), "FUND%d", fund);

        fund++;
    }

    else if(strcmp(init.tipo, "STOCK") == 0) {

        snprintf(p->nome, sizeof(p->nome), "STOCK%d", stock);

        stock++;
    }

    else if(strcmp(init.tipo, "DESCARTE") == 0) {

        snprintf(p->nome, sizeof(p->nome), "DESCARTE%d", descarte);

        descarte++;
    }

    else if(strcmp(init.tipo, "CELL") == 0) {

        snprintf(p->nome, sizeof(p->nome), "CELL%d", cell);

        cell++;
    }

    strcpy(p->tipo, init.tipo);

    for(t = 0; t < j->regras.numTipos; t++) {

        if(strcmp(j->regras.tipos[t].nome, init.tipo) == 0) {

            p->visivel = j->regras.tipos[t].flags[0];
        }
    }

    iniciar_pilha(&p->pilha);

    for(c = 0; c < init.quantidade; c++) {

        adiciona_carta(&p->pilha, tirar_carta(&j->baralho));
    }

    j->numPilhas++;
    }
}

int sequenciaValida(Pilha *p, int pos, int quantidade, int mesmoNaipe) {

    int i;

    for(i = pos; i < pos + quantidade - 1; i++) {

        Carta atual;
        Carta seguinte;

        atual = ver_carta(p, i);

        seguinte = ver_carta(p, i + 1);

        if(valor_numerico(atual) != valor_numerico(seguinte) + 1) {

            return 0;
        }

        if(mesmoNaipe) {

            if(get_naipe(atual) != get_naipe(seguinte)) {

                return 0;
            }
        }
    }

    return 1;
}



















int validarValores(RegraMovimento *m, Carta origem, Carta destino) {

int vo;
int vd;

vo = valor_numerico(origem);
vd = valor_numerico(destino);

/* regra '~' */

if(temFlag(m->flags, '~')) {

    return vo == vd - 1 || vo == vd + 1;
}

/* regra '<' */

if(temFlag(m->flags, '<')) {

    return vo == vd - 1;
}

/* regra '>' */

if(temFlag(m->flags, '>')) {

    return vo == vd + 1;
}

return 1;
}

int regraValida(Jogo *j, RegraMovimento *m, int origem, int destino, int quantidade) {

Pilha *pOrigem;
Pilha *pDestino;

Carta cartaOrigem;
Carta cartaDestino;

pOrigem = &j->pilhas[origem].pilha;
pDestino = &j->pilhas[destino].pilha;

cartaOrigem = ver_carta(pOrigem, pOrigem->topo - quantidade);

if((temFlag(m->flags,'v') || temFlag(m->flags, 'V')) && !pilha_vazia(pDestino)) {

return 0;

}


if(!validarQuantidade(m, quantidade)) {

    return 0;
}

if(!validarSequencia(j, m, origem, quantidade)) {

    return 0;
}

if(pilha_vazia(pDestino)) {

    return validarDestinoVazio(m, cartaOrigem);
}

cartaDestino = ver_topo(pDestino);

if(!validarValores(m, cartaOrigem, cartaDestino)) {

    return 0;
}

if(!validarNaipe(m, cartaOrigem, cartaDestino)) {

    return 0;
}

if(!validarCor(m, cartaOrigem, cartaDestino)) {

    return 0;
}

return 1;

}


int validarCor(RegraMovimento *m, Carta origem, Carta destino) {

    if(temFlag(m->flags, 'd') || temFlag(m->flags, 'D')) {

    return cor_carta(origem) != cor_carta(destino);
    }
return 1;
}

int validarDestinoVazio(RegraMovimento *m, Carta carta) {

if(temFlag(m->flags, 'a')) {

    return valor_numerico(carta) == 1;
}

if(temFlag(m->flags, 'K')) {

    return valor_numerico(carta) == 13;
}

if(temFlag(m->flags, 'v') ||  temFlag(m->flags,'V')) {

    return 1;
}

return 0;
}



int validarSequencia(Jogo *j, RegraMovimento *m, int origem, int quantidade) {

Pilha *p;

int pos;
int mesmoNaipe;

p = &j->pilhas[origem].pilha;

if(!temFlag(m->flags, '+')) {

    return 1;
}

pos = p->topo - quantidade;

mesmoNaipe = temFlag(m->flags, 'm');

return sequenciaValida(p, pos, quantidade, mesmoNaipe);
}


int validarQuantidade(RegraMovimento *m, int quantidade) {

if(temFlag(m->flags, '-')) {

    return quantidade == 1;
}

return 1;
}


int validarNaipe(RegraMovimento *m, Carta origem, Carta destino) {

if(temFlag(m->flags, 'M') || temFlag(m->flags, 's')) {

    return get_naipe(origem) == get_naipe(destino);
}

return 1;
}

int movimentoCompativel(Jogo *j, RegraMovimento *m, int origem, int destino) {

return strcmp(m->origem, j->pilhas[origem].tipo) == 0 && strcmp(m->destino, j->pilhas[destino].tipo) == 0;
}

int pilhaAceitaCarta(Jogo *j, int origem, int destino, int quantidade) {

int i;

for(i = 0; i < j->regras.numMovimentos; i++) {

    RegraMovimento *m;

    m = &j->regras.movimentos[i];

    if(movimentoCompativel(j, m, origem, destino)) {

        if(regraValida(j, m, origem, destino, quantidade)) {

            return 1;
        }
    }
}

return 0;

}
























int maiorSequenciaMovivel(Jogo *j, int origem, int destino) {

int i;

Pilha *p;

p = &j->pilhas[origem].pilha;

for(i = 0; i < j->regras.numMovimentos; i++) {

    RegraMovimento *m;

    m = &j->regras.movimentos[i];

    if(movimentoCompativel(j, m, origem, destino)) {

        /* regra sem '+' */

        if(!temFlag(m->flags, '+')) {

            if(pilhaAceitaCarta(j, origem, destino, 1)) {

                return 1;
            }
        }

        /* regra com '+' */

        else {

            int n;

            for(n = p->topo + 1; n >= 1; n--) {

                if(pilhaAceitaCarta(j, origem, destino, n)) {

                    return n;
                }
            }
        }
    }
}

return 0;
}

int moverCartas(Jogo *j, int origem, int destino, int quantidade) {

Carta bloco[52];

Pilha *pOrigem;
Pilha *pDestino;

int pos;
int i;

if(origem < 0 || origem >= j->numPilhas) {

    return 0;
}

if(destino < 0 || destino >= j->numPilhas) {

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

if(!pilhaAceitaCarta(j, origem, destino, quantidade)) {

    return 0;
}

pos = pOrigem->topo - quantidade;

for(i = 0; i < quantidade; i++) {

    bloco[i] = ver_carta(pOrigem, pos + i);
}

adicionar_n_cartas(pDestino, bloco, quantidade);

remover_n_cartas(pOrigem, quantidade);

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

            int quantidade;

            if(o != d) {

                if(strcmp(j->pilhas[o].tipo, a->origem) == 0 && strcmp(j->pilhas[d].tipo, a->destino) == 0) {

                    quantidade = maiorSequenciaMovivel(j, o, d);

                    if(quantidade > 0) {

                        moverCartas(j, o, d, quantidade);

                        return 1;
                    }
                }
            }
        }
    }
}

return 0;
}


int existeJogadaPossivel(Jogo *j){
    int o;
    int d;

    for(o = 0; o < j->numPilhas; o++) {

        for(d = 0; d < j->numPilhas; d++) {

            if(o != d) {

                if(maiorSequenciaMovivel(j, o, d) > 0) {

                    return 1;
                }
            }
        }
    }

    return 0;
}

int encontrarAjuda(Jogo *j, int *origem, int *destino) {

    int o;
    int d;

    for(o = 0; o < j->numPilhas; o++) {

        for(d = 0; d < j->numPilhas; d++) {

            if(o != d) {

                if(maiorSequenciaMovivel(j, o, d) > 0) {

                    *origem = o;

                    *destino = d;

                    return 1;
                }
            }
        }
    }

    return 0;
}

void guardarUndo(Jogo *j) {

    j->undo.baralho = j->baralho;

    j->undo.numPilhas = j->numPilhas;

    memcpy(j->undo.pilhas, j->pilhas, sizeof(j->pilhas));

    j->existeUndo = 1;
}


void desfazerJogada(Jogo *j) {

    if(!j->existeUndo) {

        return;
    }

    j->baralho = j->undo.baralho;

    j->numPilhas = j->undo.numPilhas;

    memcpy(j->pilhas, j->undo.pilhas, sizeof(j->pilhas));

    j->existeUndo = 0;
}

int verificarWin(Jogo *j) {

int w;
int p;

for(w = 0; w < j->regras.numWins; w++) {

    int encontrou = 0;

    RegraWin *win;

    win = &j->regras.wins[w];

    for(p = 0; p < j->numPilhas; p++) {

        if(strcmp(j->pilhas[p].tipo, win->tipo) == 0) {

            encontrou = 1;

            if(j->pilhas[p].pilha.topo + 1 != win->objetivo) {

                return 0;
            }
        }
    }

    if(!encontrou) {

        return 0;
    }
}

return 1;
}


int jogoTerminou(Jogo *j) {

    if(verificarWin(j)) {

        return 1;
    }

    if(!existeJogadaPossivel(j)) {

        return 1;
    }

    return 0;
}
void mostrarJogo(Jogo *j) {

int i;
int c;

printf("JOGO: %s\n\n", j->regras.nomeJogo);

for(i = 0; i < j->numPilhas; i++) {

    printf("%s: ", j->pilhas[i].nome);

    /* pilha escondida */

    if(j->pilhas[i].visivel == '_') {

        printf("[%d cartas]", j->pilhas[i].pilha.topo);
    }

    /* mostrar apenas topo */

    else if(j->pilhas[i].visivel == '^' || strcmp(j->pilhas[i].tipo, "DESCARTE") == 0) {

    if(!pilha_vazia( &j->pilhas[i].pilha)) {

    imprimir_carta(ver_topo(&j->pilhas[i].pilha ));
    }
    }

    /* mostrar tudo */

    else {

        for(c = 0; c < j->pilhas[i].pilha.topo; c++) {

            imprimir_carta(j->pilhas[i].pilha.cartas[c]);
        }
    }

    printf("\n");
}
}

int guardarJogo(Jogo *j, const char *ficheiro, const char *ficheiroPaciencia) {

    FILE *f;

    int p;
    int c;
    
    mkdir("saves", 0777);

    char caminho[128];

    snprintf(caminho, sizeof(caminho), "saves/%s", ficheiro);

    f = fopen(caminho, "w");

    if(f == NULL) {

        return 0;
    }

    /* nome da paciencia */

    fprintf(f, "%s\n", ficheiroPaciencia);

    /* pilhas */

    for(p = 0; p < j->numPilhas; p++) {

        for(c = 0; c < j->pilhas[p].pilha.topo; c++) {

            Carta carta;

            carta = j->pilhas[p].pilha.cartas[c];

            escrever_carta(f, carta);

            fprintf(f, " ");
        }

        fprintf(f, "\n");
    }

    fclose(f);

    return 1;
}

int carregarJogo(Jogo *j, const char *ficheiro, char *ficheiroPaciencia) {

    FILE *f;

    char caminho[128];

    int p;

    snprintf(caminho, sizeof(caminho), "saves/%s", ficheiro);

    f = fopen(caminho, "r");

    if(f == NULL) {

        return 0;
    }

    /* ler nome da paciencia */

    fscanf(f, "%s", ficheiroPaciencia);

    fgetc(f);

    /* iniciar jogo */

    iniciarJogo(j, ficheiroPaciencia);

    /* limpar pilhas */

    for(p = 0; p < j->numPilhas; p++) {

        j->pilhas[p].pilha.topo = 0;
    }

    /* carregar cartas */

   for(p = 0; p < j->numPilhas; p++) {

    char linha[256];

    if(fgets(linha, sizeof(linha), f) != NULL) {

        char *token;

        token = strtok(linha, " \n");

        while(token != NULL) {

            Carta carta;

            carta = ler_carta(token);

            adiciona_carta(&j->pilhas[p].pilha, carta);

            token = strtok(NULL, " \n");
        }
    }
}

    fclose(f);

    return 1;
}

