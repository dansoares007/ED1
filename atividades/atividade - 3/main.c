#include "TLList.h"
#include <stdio.h>

int main(){
    TLList* lista1 = TLList_create();
    
    int V[] = {5, 1, 3, 2, 4}, i;
    for(i = 0; i<5; i++)
        if(!TLList_insert(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    TLList_print(lista1);
    
    int n;
    int posicao;

    retornar_maior(lista1, &n, &posicao);

    printf("O maior número é %d na posição %d\n", n, posicao);
    
    return 0;
}
