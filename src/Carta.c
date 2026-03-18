#include <stdio.h>
#include "Carta.h"

// Estrutura de uma carta
typedef struct carta
{
    char valor;
    char naipe;
};

char valores[] = {'A','2','3','4','5','6','7','8','9','T','V','D','R'};
char naipes[] = {'E','P','C','O'};


// Carta baralho[];

//funcao que torna o caracter num numero inteiro
int valorCarta (Carta c){
    switch (c.valor) {
   case 'A': return 1; 
   case '2': return 2; 
   case '3': return 3; 
   case '4': return 4; 
   case '5': return 5; 
   case '6': return 6; 
   case '7': return 7; 
   case '8': return 8; 
   case '9': return 9; 
   case 'T': return 10;
   case 'J': return 11;
   case 'Q': return 12;
   case 'K': return 13;
   default: return 0;
    }
}

//funcao que cria uma carta, sendo a posicao 0 o valor numerico 
// e a posicao 1 o naipe da mesma
Carta criarCarta(char *str){
    Carta c;
    c.valor=str[0];
    c.naipe=str[1];
    return c;
}

int cartaIgual(Carta a, Carta b){
return (a.valor==b.valor && a.naipe==b.naipe) ? 1 : 0 ;
}


//funcao que verifica se duas cartas sao adjacentes
//O Rei nao pode ser adjacente ao As, nem vice-versa
int cartaAdjacente(Carta a, Carta b){
int va = valorCarta(a);
int vb = valorCarta(b);
return (va-vb==1 || vb-va==1 ) ? 1 : 0 ;
}

int main() {
    /*char *BaralhoString[52]={"AE","2E","3E","4E","5E","6E","7E","8E","9E","TE","JE","QE","KE",
        "AP","2P","3P","4P","5P","6P","7P","8P","9P","TP","JP","QP","KP",
        "AC","2C","3C","4C","5C","6C","7C","8C","9C","TC","JC","QC","KC",
        "AO","2O","3O","4O","5O","6O","7O","8O","9O","TO","JO","QO","KO"
    };
    
    Carta Baralho[52];
    for (int i = 0; i < 52; i++)
    {
    Baralho[i]=criarCarta(BaralhoString[i]);
    }
    
    for (int i = 0; i < 52; i++)
    {
        printf("Carta: %s, Valor=%d\n", BaralhoString[i],valorCarta(Baralho[i]));
    }
    
Carta a=criarCarta("AE");
Carta b=criarCarta("KE");
Carta b=criarCarta("2E");
Carta b=criarCarta("AO");
Carta b=criarCarta("AE");
if (cartaAdjacente(a,b))
    printf("%c%c e %c%c são adjacentes\n", a.valor,a.naipe,b.valor,b.naipe);
else
    printf("%c%c e %c%c não são adjacentes\n", a.valor,a.naipe,b.valor,b.naipe);


Carta a=criarCarta("AE");
Carta b=criarCarta("AE");
Carta c=criarCarta("T0");
if(cartaIgual(a,c)){
    printf("igual\n");
}else{
    printf("nem perto\n");
}
*/
}