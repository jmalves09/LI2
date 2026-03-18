#define MAX_PILHAS 7

typedef struct{
    Pilha baralho; //baralho
    Pilha mesa[MAX_PILHAS]; // pilhas da mesa
} Jogo;

void iniciarJogo (Jogo *j){

    iniciarBaralho(j);
    estaCheia(j);

    return ;

}

int jogadaValida(Jogo *j,Carta c, Pilha baralho){
   
retiraCarta(baralho);
cartaAdjacente(c);

return ;


}
Carta tirarCartaBaralho(Jogo *j){
 
    tirarCarta(j);



return;


}
void fazJogada(Jogo *j,Carta c, Pilha baralho) {


criarCarta(c);
retiraCarta(c);
    return;
}