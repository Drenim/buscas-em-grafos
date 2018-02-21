#include "TADgrafo.h"
#ifndef _TAD_FILA_HEADER_
#define _TAD_FILA_HEADER_

/*  Neste arquivo constam as definições de funções e tipo necessárias para a implementação
    de uma fila. Esta estrutura é utilizada na implementação do algoritmo bfs. */


/*  Uma fila é uma lista encadeada do tipo fila na qual os elementos são inseridos na última
    posição e retirados na primeira (FIFO). */

struct fila_vert{
    t_vertice *vert;
    struct fila_vert *ant;
};

typedef struct fila_vert fila;

/*  DEFINIÇÃO: Uma fila está vazia se e somente se ambos os ponteiros de
    início e fim apontam para NULL. */

/*  Dados dois ponteiros para ponteiros de uma fila, incializa esses ponteiros
    com NULL. Não possui retorno. */
void inicializafila(fila **fim, fila **inicio);

/*  Dado um vértice de um grafo e os ponteiros de inicio e fim
    de fila, coloca o vértice na fila. Não possui retorno. */
void enqueue(t_vertice *vertice, fila **fim, fila **inicio);

/*  Dados dois ponteiros para ponteiros para o início e o fim de uma
    fila, remove um elemento da fila (de acordo com a política FIFO) e 
    retorna o endereço desse elemento. ASSUME QUE A FILA NÃO ESTÁ VAZIA. */
t_vertice * dequeue(fila **fim, fila **inicio);

/*  Dados dois ponteiros para o inicio e o fim da fila, retorna 1 caso 
    a fila esteja vazia e 0 caso contrário. */
int estavazia(fila *fim, fila *inicio);

#endif