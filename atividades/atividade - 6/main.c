#include "TLList.h"
#include <stdio.h>

int main(){
    TLList* lista1 = TLList_create();
    TLList* lista2 = TLList_create();
    
    int V[] = {1, 2, 3, 4, 5}, i;
    for(i = 0; i<5; i++)
        if(!TLList_insert(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    TLList_print(lista1);

    lista2 = inverter_lista(lista1);
    TLList_print(lista2);
    
    return 0;
}
