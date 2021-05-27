/*
 * NOME: Dener Silva
 * EXERCICIO: Lista simplesmente encadeada COM Sentinela.
*/
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(){
    TipoLista* l = InicializaLista();

    TipoItem* dener = InicializaTipoItem("dener", 123, "rua de dener");
    TipoItem* pablo = InicializaTipoItem("pablo", 789, "rua de pablo");
    TipoItem* jose = InicializaTipoItem("jose", 111, "rua de jose");
    
    Insere (dener, l);
    Insere (pablo, l);
    Insere (jose, l);
    printf("\n********* Pessoas numa lista *********\n\n");
    Imprime (l);
    
    TipoItem* retirado;
    retirado = Retira(l, 000);
    if(retirado != NULL){
        Imprime(l);
    }
    else{
        printf("\nNao foi possivel retirar o numero 000 da lista!\n");
    }
    retirado = Retira (l, 123);
    if(retirado != NULL){
        printf("\n********* Lista atualizada *********\n\n");
        Imprime(l);
    }
    else{
        printf("\nNao foi possivel retirar o numero 123 da lista!\n");
    }
    

    
    l = Libera (l);

    return 0;
}