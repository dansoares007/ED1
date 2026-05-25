#include "TLList.h"
#include <stdio.h>

int main(){
    TLList* lista1 = TLList_create();
    TLList* lista2 = TLList_create();
    
    int V[] = {5, 1, 3, 2, 4}, i;
    for(i = 0; i<5; i++)
        if(!TLList_insert(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    TLList_print(lista1);
    
    lista2 = retornar_par(lista1);
    TLList_print(lista2);
}
