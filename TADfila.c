#include <stdlib.h>
#include "TADgrafo.h"
#include "TADfila.h"

/*  Neste arquivo estão as implementações das funções definidas no arquivo TADfila.h */


/*  Dados dois ponteiros para ponteiros de uma fila, incializa esses ponteiros
    com NULL. Não possui retorno. */
void inicializafila(fila **fim, fila **inicio){
    *inicio = NULL;
    *fim = NULL;
}


/*  Dado um vértice de um grafo e os ponteiros de inicio e fim
    de fila, coloca o vértice na fila. Não possui retorno. */
void enqueue(t_vertice *vertice, fila **fim, fila **inicio){
    fila * aux;
    aux = malloc(sizeof (fila));
    if (aux == NULL) exit(EXIT_FAILURE);
    aux->vert = vertice;
    
    aux->ant = NULL;

    if (*inicio == NULL && *fim == NULL){
        *inicio = aux;
        *fim = aux;
    }else{
        (*fim)->ant = aux;
        *fim = aux;
    }
}


/*  Dados dois ponteiros para ponteiros para o início e o fim de uma
    fila, remove um elemento da fila (de acordo com a política FIFO) e 
    retorna o endereço desse elemento. ASSUME QUE A FILA NÃO ESTÁ VAZIA. */
t_vertice * dequeue(fila **fim, fila **inicio){
    t_vertice *vertice;
    fila *aux = 
    
    aux = *inicio;

    *inicio = aux->ant;
    vertice = aux->vert;
    if (*inicio == NULL)
        *fim = NULL;
    free(aux);
    return vertice;
}


/*  Dados dois ponteiros para o inicio e o fim da fila, retorna 1 caso 
    a fila esteja vazia e 0 caso contrário. */
int estavazia(fila *fim, fila *inicio){
    if (fim == inicio && inicio == NULL)
        return 1;
    return 0;
}