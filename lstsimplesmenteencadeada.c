/*
 * NOME: Dener Silva
 * EXERCICIO: Lista simplesmente encadeada COM Sentinela.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

struct tipoitem{
    char* nome;
    int matricula;
    char* endereco;
};

typedef struct cel Cel;

struct cel{
    TipoItem* info;
    struct cel* prox;
};

struct tipolista{
    Cel* prim;
    Cel* ult;
};

TipoLista* InicializaLista(){
    TipoLista* l = (TipoLista*)malloc(sizeof(TipoLista));
    l->prim = NULL;
    l->ult = NULL;
    return (l);
}

void Insere (TipoItem* aluno, TipoLista* lista){
    Cel* novo = (Cel*)malloc(sizeof(Cel));
    
    //Povoa os campos da celula
    novo->info = aluno;
    novo->prox = NULL;

    //Acerta o encadeamento
    if(lista->prim == NULL){//Se a lista estiver vazia
        lista->prim = novo;
        lista->ult = novo;
    }
    else{//Encadeia no final da lista
        lista->ult->prox = novo;
        lista->ult = novo;
    }
}

TipoItem* Retira (TipoLista* lista, int mat){
    Cel* p = lista->prim;
    Cel* ant;
    while(p != NULL && p->info->matricula != mat){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        return NULL;
    }
    if(p == lista->prim && p == lista->ult){//So tem 1 elemento na lista.
        lista->prim = NULL;
        lista->ult = NULL;
        return (p->info);
        //free(p);
    }
    if(p == lista->prim){//O elemento eh o primeiro da lista.
        lista->prim = p->prox;
        return(p->info);
        //free(p);
    }
    if(p == lista->ult){//O elemento eh o ultimo da lista.
        lista->ult = ant;
        ant->prox = NULL;
        return(p->info);
        //free(p);
    }
    else{//O elemento esta no meio da lista.
        ant->prox = p->prox;
        return(p->info);
    }
    free(p->info->nome);
    free(p->info->endereco);
    free(p->info);
    free(p);
}

void Imprime (TipoLista* lista){
    Cel* p = lista->prim;
    while(p != NULL){
        printf("NOME: %s\tMATRICULA: %d\tENDERECO: %s\n", p->info->nome, p->info->matricula, p->info->endereco);
        p = p->prox;
    }
}

TipoLista* Libera (TipoLista* lista){
	Cel* atual = lista->prim;
	while(atual != NULL){
		Cel* proximo = atual->prox;

		free(atual->info->nome);
		free(atual->info->endereco);
		free(atual->info);
        free(atual);
		
		atual = proximo;
	}
	free(lista);
	return NULL;
}

TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){
    TipoItem* new = (TipoItem*)malloc(sizeof(TipoItem));
    new->nome = (char*)malloc( (strlen(nome)+1)*sizeof(char) );
    strcpy(new->nome, nome);
    new->endereco = (char*)malloc( (strlen(endereco)+1)*sizeof(char) );
    strcpy(new->endereco, endereco);
    new->matricula = matricula;

    return (new);
}