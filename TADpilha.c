#include <stdlib.h>
#include "TADgrafo.h"
#include "TADpilha.h"

/*  Este arquivo, e o arquivo TADpilha.h compõem a definição de uma
    pilha de vértices, necessãria para implementar o algoritmo DFS. */


/*  Dado o ponteiro-de-ponteiro do topo da pilha, inicializa o topo com
    NULL (deixando a pilha vazia). */
void inicializapilha(pilha **topo){
    *topo = NULL;
}


/*  Dado o endereço de um vértice e o endereço do um ponteiro para uma pilha,
    insere o vértice na pilha. Não possui retorno. */
void push(t_vertice *vertice, pilha **topo){
    pilha * aux;
    aux = malloc(sizeof (pilha));
    if (aux == NULL) exit(EXIT_FAILURE);

    aux->vert = vertice;
    if (*topo == NULL)
        aux->embaixo = NULL;
    else
        aux->embaixo = *topo;

    *topo = aux; 
}


/*  Dado o ponteiro para um ponteiro que aponta para o topo da pilha, remove
    o vértice do topo e retorna o endereço desse vértice. ASSUME QUE A PILHA 
    NÃO ESTÁ VAZIA. */
t_vertice * pop(pilha **topo){
    pilha *aux;
    t_vertice *ret;

    ret = (*topo)->vert;
    aux = *topo;
    *topo = (*topo)->embaixo;
    free(aux);
    
    return ret;
}


/*  Recebe o endereço do topo da pilha. Retorna 1 se pilha estiver vazia e 0 
    caso contrário. */
int estavaziap(pilha *topo){
    if (topo == NULL)
        return 1;
    return 0;
}