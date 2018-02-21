#include <stdio.h>
#include <stdlib.h>
#include "TADgrafo.h"
#include "TADfila.h"
#include "TADpilha.h"

/*  Neste arquivo constam as implementações das funções descritas no 
    arquivo TADgrafo.h */


/*  Recebe o ponteiro para um arquivo (*FILE) texto aberto em modo leitura e formatado 
    conforme as especificações, e o endereço de um inteiro onde será armazenado 
    o número de vértices do grafo. Retorna um grafo simples (lista de adjacência) 
    construído a partir da leitura do arquivo e o número de vértices em *nvertices. 
    OBS.: NÃO FECHA O ARQUIVO. */
t_vertice * constroigrafo(FILE *arq, int *nvertices){
    int n, m, i, vert_in, vert_out, swap;
    t_vertice * grafo;
    t_adjacente *aux;

    fscanf(arq, "%d %d\n", &n, &m);
    grafo = malloc(n * sizeof (t_vertice));
    if (grafo == NULL) exit(EXIT_FAILURE);

    for (i = 0; i < n; i++){
        grafo[i].label = i;
        grafo[i].visitado = 0;
        grafo[i].adjacentes = NULL;
        grafo[i].distancia = -1;
    }

    while (m > 0){
        fscanf(arq, "%d %d\n", &vert_in, &vert_out);
        aux = malloc(sizeof (t_adjacente));
        if (aux == NULL) exit(EXIT_FAILURE);

        aux->label = vert_out;
        aux->elo = grafo[vert_in].adjacentes;
        grafo[vert_in].adjacentes = aux;

        swap = vert_in;
        vert_in = vert_out;
        vert_out = swap;

        aux = malloc(sizeof (t_adjacente));
        if (aux == NULL) exit(EXIT_FAILURE);

        aux->label = vert_out;
        aux->elo = grafo[vert_in].adjacentes;
        grafo[vert_in].adjacentes = aux;


        m--;
    }    

    *nvertices = n;
    return grafo;
}

/*  Recebe um grafo simples (lista de adjacência) alocado dinâmicamente e o destrói. 
    Retorna sempre NULL, para setar o ponteiro. */
t_vertice * destroigrafo(t_vertice grafo[], int nvertices){
    int j;
    t_adjacente *aux, *i;

    for (j = 0; j < nvertices; j++){
        i = grafo[j].adjacentes;
        while(i != NULL){
            aux = i->elo;
            free(i);
            i = aux;
        }
    }
    free(grafo);
    return NULL;
}


/*  Recebe um grafo simples (lista de adjacência) e seu número de vértices. 
    Imprime-o na tela.*/
void printgrafo(t_vertice grafo[], int nvertices){
    int j;
    t_adjacente *i;

    for (j = 0; j < nvertices; j++){
        for (i = grafo[j].adjacentes; i != NULL; i = i->elo){
            printf("%d %d\n", grafo[j].label, i->label);
        }
    }
}


/*  Recebe um grafo simples (lista de adjancência) e o endereço de um vértice inicial. 
    Realiza busca em largura (marca os vértices como visitados). Não possui retorno. */
void bfs(t_vertice grafo[], t_vertice *start){
    t_vertice *vert;
    fila *fim, *inicio;
    t_adjacente *i;

    inicializafila(&fim, &inicio);
    
    start->visitado = 1;
    enqueue(start, &fim, &inicio);

    while (!estavazia(fim, inicio)){
        vert = dequeue(&fim, &inicio);

        i = vert->adjacentes;
        for (; i != NULL; i = i->elo){
            if (grafo[i->label].visitado == 0){
                grafo[i->label].visitado = 1;
                enqueue(&grafo[i->label], &fim, &inicio);
            }
        }

    }
    
}


/*  Realiza o cálculo do número de componentes conexos em um grafo simples (usando bfs),
    dado um grafo (lista de adjacência) e seu número de vérices. 
    Exibe na tela o resultado.
    Não possui retorno. */
void componentesbfs(t_vertice grafo[], int nvertices){
    int i, contador;

    contador = 0;
    for (i = 0; i < nvertices; i++){
        if (grafo[i].visitado == 0){
            contador++;
            bfs(grafo, &grafo[i]);
        }
    }

    printf("%d ", contador);

} 


/*  Calcula as distâncias do vértice 0 a todos os demais vértices (usando bfs). 
    Recebe um grafo simples (lista de adjacência) e seu número de vértices.
    Exibe o resultado na tela, conforme a especificação. Não possui retorno. */
void distanciasbfs(t_vertice grafo[], int nvertices){
    int j;
    t_vertice *vert;
    fila *fim, *inicio;
    t_adjacente *i;

    inicializafila(&fim, &inicio);
    
    grafo[0].visitado = 1;
    grafo[0].distancia = 0;
    enqueue(&grafo[0], &fim, &inicio);

    while (!estavazia(fim, inicio)){
        vert = dequeue(&fim, &inicio);

        i = vert->adjacentes;
        for (; i != NULL; i = i->elo){
            if (grafo[i->label].visitado == 0){
                grafo[i->label].visitado = 1;
                grafo[i->label].distancia = (vert->distancia) + 1;
                enqueue(&grafo[i->label], &fim, &inicio);
            }
        }

    }

    for (j = 0; j < nvertices; j++){
        printf("%d ", grafo[j].distancia);
    }
    
}


/*  Realiza dfs em um grafo simples. Recebe o grafo e o endereço de um vértice inicial.
    Não possui retorno. */
void dfs (t_vertice grafo[], t_vertice *start){
    t_vertice *vert;
    t_adjacente *i;
    pilha *topo;

    inicializapilha(&topo);

    start->visitado = 1;
    push(start, &topo);

    while(estavaziap(topo) == 0){
        vert = pop(&topo);
        
        for (i = vert->adjacentes; i != NULL; i = i->elo){
            if (grafo[i->label].visitado == 0){
                push(&grafo[i->label], &topo);
                grafo[i->label].visitado = 1;
            }
        }
    }
}


/*  Recebe um grafo simples (grafo - lista de adjacência) e seu número de vértices. 
    Calcula as distâncias do vértice 0 a todos os demais vértices (usando dfs. 
    Exibe o resultado na tela. Não possui retorno. */
void distanciasdfs (t_vertice grafo[], int nvertices){
    int j;
    t_vertice *vert;
    t_adjacente *i;
    pilha *topo;

    inicializapilha(&topo);

    grafo[0].visitado = 1;
    grafo[0].distancia = 0;
    push(&grafo[0], &topo);

    while(estavaziap(topo) == 0){
        vert = pop(&topo);
        
        for (i = vert->adjacentes; i != NULL; i = i->elo){
            if (grafo[i->label].visitado == 0){
                push(&grafo[i->label], &topo);
                grafo[i->label].visitado = 1;
                grafo[i->label].distancia = vert->distancia + 1;
            }
        }
    }
    
    for (j = 0; j < nvertices; j++)
        printf("%d ", grafo[j].distancia);

}


/*  Recebe um grafo simples (lista de adjacência) e seu número de vértices. Calcula o número
    de componentes conexos do grafo (usando dfs) e exibe o resultado na tela. Não possui retorno. */
void componentesdfs(t_vertice grafo[], int nvertices){
    int i, contador = 0;

    for (i = 0; i < nvertices; i++){
        if (grafo[i].visitado == 0){
            dfs(grafo, &grafo[i]);
            contador++;
        }
    }
    printf("%d ", contador);
}
