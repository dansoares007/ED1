#ifndef TLLIST_H
#define TLLIST_H
#include <stdbool.h>

typedef struct _list TLList;
/**
 * Cria instâncias da TLList;
 */
TLList* TLList_create();
/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TLList_insert(TLList*, int);

void TLList_print(TLList*);

/**
 * Imprime a lista do início para o fim.
 */
bool TLList_remove(TLList *, int);

// 5. Fazer uma função para realizar cópia uma lista L1 em outra L2, eliminando os elementos
// repetidos. L2 deverá ser retornada pela função.

bool contem_repetido(TLList *, int);

TLList *copia_sem_repetidos(TLList*, TLList*);

#endif