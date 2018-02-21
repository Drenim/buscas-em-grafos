#include "TADgrafo.h"
#ifndef _TAD_PILHA_HEADER
#define _TAD_PILHA_HEADER

/*  Este arquivo, e o arquivo TADpilha.c compõem a definição de uma
    pilha de vértices, necessãria para implementar o algoritmo DFS. */


/*  Uma pilha é uma lista encadeada do tipo pilha, na qual cada elemento é inserido e retirado
    no "topo" (LIFO). */    

struct p_vert{
    t_vertice *vert;
    struct p_vert *embaixo;
};

typedef struct p_vert pilha;

/*  DEFINIÇÃO: Uma pilha está vazia se e somente se seu ponteiro para o 
    topo aponta para NULL. */

/*  Dado o ponteiro-de-ponteiro do topo da pilha, inicializa o topo com
    NULL (deixando a pilha vazia). */
void inicializapilha(pilha **topo);

/*  Dado o endereço de um vértice e o endereço do um ponteiro para uma pilha,
    insere o vértice na pilha. Não possui retorno. */
void push(t_vertice *vertice, pilha **topo);

/*  Dado o ponteiro para um ponteiro que aponta para o topo da pilha, remove
    o vértice do topo e retorna o endereço desse vértice. ASSUME QUE A PILHA 
    NÃO ESTÁ VAZIA. */
t_vertice * pop(pilha **topo);

/*  Recebe o endereço do topo da pilha. Retorna 1 se pilha estiver vazia e 0 
    caso contrário. */
int estavaziap(pilha *topo);

#endif

