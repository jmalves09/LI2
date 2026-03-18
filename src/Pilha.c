#include <stdio.h>
#include <stdbool.h>
#include "Pilha.h"
#include "Carta.h"

//numero maximo do baralho
#define MAX 52

typedef struct pilha
{
    int cartas[MAX];
    int topo;
};

//funcao inicia pilha 
//stack esta vazia
void iniciar (Pilha*  pilha){
    pilha->topo = -1;
}

/* Funcao que verifica se a pilha esta vazia */ 
bool estaVazia(Pilha *pilha){
    return pilha->topo==-1;
}

//funcao que verifica se a pilha esta cheia
bool estaCheia(Pilha *pilha){
    return pilha->topo==MAX-1;
}

//funcao que adiciona carta no topo da pilha
void adiciona(Pilha *p, Carta c){
    if(estaCheia(p)){
        printf ("Pilha esta cheia\n");
    } else {
    p->topo++;
    p->cartas[p->topo]=c;
    printf ("%s adicionada na pilha\n",c);
 }
}

//funcao que retira carta da pilha
void retiraCarta(Pilha *p){
    if(estaVazia(p)){
        printf("pilha esta vazia");
    }else{
   Carta c = p->cartas[p->topo];
   p->topo--;
        printf("%s saiu da pilha\n",c);
    }
}

void baralhar(Pilha* b){
    for(int i=0; i<b->topo; i++){
        int j=rand()%52+i;

        Carta temp= b->cartas[i];
        b->cartas[i]=b->cartas[j];
        b->cartas[j]=temp;
    }
}


//POR TESTAR
int main(){
    Pilha baralho;

    iniciar(&baralho);

    adiciona(&baralho, criarCarta("AE"));
    adiciona(&baralho, criarCarta("TO"));

    retiraCarta(&baralho);

}