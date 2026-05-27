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

bool TLList_remove(TLList *lista, int numero_remover){
    TNo **aux = &(lista->inicio);
    if(*aux == NULL) return false;
    TNo *remover = *aux;
    while(*aux != NULL && (*aux)->info != numero_remover){
        aux = &(*aux)->prox;
    }
    *aux = (*aux)->prox;
    free(remover);
    return true;
}

bool TLList_insert_end(TLList *lista, int info){
    if(lista == NULL) return false;
    TNo** aux = &(lista->inicio);
    TNo* novo = TNo_createNFill(info);
    if(novo == NULL) return false;

    while(*aux != NULL){
        aux = &(*aux)->prox;
    }

    *aux = novo;

    return true;
}

TLList *inverter_lista(TLList *lista1){
    if(lista1 == NULL) return NULL;
    TLList *lista2 = TLList_create();   
    if(lista2 == NULL) return NULL;
    
    TNo* aux = lista1->inicio;
    
    while(aux != NULL){
        TNo* novo = TNo_createNFill(aux->info);
        if(novo != NULL){
            novo->prox = lista2->inicio;
            lista2->inicio = novo;
        }
        
        aux = aux->prox;
    }
    return lista2;
}
