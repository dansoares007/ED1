#include "TLList.h"
#include<stdio.h>
#include <stdlib.h>

//estrutura auxiliar para as ligações dos nós
typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
};
//Funcao auxiliar para preencher um nó
TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo != NULL)
    {
        novo->prox = NULL;
        novo->info = info;
    }
    return novo;
}

TLList* TLList_create(){
    TLList* nova = malloc(sizeof(TLList));
    if(nova != NULL){
        nova->inicio = NULL;
    }
    return nova;
}
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TLList_insert(TLList* lista, int info){
    //Inicializando um TNo novo para a nova informação
    TNo* novo = TNo_createNFill(info);
    if(novo == NULL) 
        return false; 
    TNo** aux = &(lista->inicio);
    while(*aux!=NULL)
        aux = &(*aux)->prox;
    *aux = novo;
    return true;
}
/**
 * Imprime a lista do início para o fim.
 */
void TLList_print(TLList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        printf("%d->", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

TLList* TLList_conca_func_tad(TLList* lista1, TLList* lista2){
    TLList* lista3=TLList_create();
    TNo* aux = lista1->inicio;
    while(aux!=NULL){
        TLList_insert(lista3, aux->info);
        aux = aux->prox;
    }
    aux = lista2->inicio;
    while(aux!=NULL){
        TLList_insert(lista3, aux->info);
        aux = aux->prox;
    }
    return lista3;
}


// 1. Faça uma função para concatenar duas listas em uma terceira lista que deverá ser retornada pela
// função. Faça duas versões: uma que utilize das funções já implementadas e outra que não usa
// qualquer função já feita do TAD.

TLList* TLList_conca_sem_tad(TLList* lista1, TLList* lista2){

    TLList *lista3 = malloc (sizeof(TLList));
    if(lista3 == NULL) return NULL;
    lista3->inicio = NULL;
    TNo *aux = lista1->inicio;
    TNo **aux2 = &(lista3->inicio);

    while(aux != NULL){
        TNo* novo = malloc (sizeof(TNo));
        if(novo == NULL) return false;
        novo->info = aux->info;
        novo->prox = NULL;
        *aux2 = novo;

        aux2 = &(*aux2)->prox;
        aux = aux->prox;
    }

        TNo *aux3 = lista2->inicio;
        while(aux3 != NULL){
            TNo* novo = malloc (sizeof(TNo));
            if(novo == NULL) return false;
            novo->info = aux3->info;
            novo->prox = NULL;
            *aux2 = novo;

            aux2 = &(*aux2)->prox;
            aux3 = aux3->prox;
        }

    return lista3;
}