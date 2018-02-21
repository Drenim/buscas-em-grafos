#include <stdio.h>
#ifndef _TAD_GRAFO_HEADER
#define _TAD_GRAFO_HEADER

/*  Neste arquivo estão as definições de funções para operar no grafo, bem como a 
    especificação dos tipos necessários para a representação do grafo em memória. */

/*  O grafo é representado por uma lista de adjacência. Aloca-se um vetor do tipo
    t_vertice, no qual cada posição representa um vértice. cada t_vertice v possui uma
    lista encadeada de t_adjacente, que armazena os labels dos vértices que são adjacentes
    a v.  */
struct T_Adjacente{
    int label;
    struct T_Adjacente *elo;
};

struct T_Vertice{
    int label;
    char visitado;
    int distancia;
    struct T_Adjacente * adjacentes; 
};

typedef struct T_Vertice t_vertice;
typedef struct T_Adjacente t_adjacente;

/*  Recebe o ponteiro para um arquivo (*FILE) texto aberto em modo leitura e formatado 
    conforme as especificações, e o endereço de um inteiro onde será armazenado 
    o número de vértices do grafo. Retorna um grafo simples (lista de adjacência) 
    construído a partir da leitura do arquivo e o número de vértices em *nvertices. 
    OBS.: NÃO FECHA O ARQUIVO. */
t_vertice * constroigrafo(FILE *arq, int *nvertices);

/*  Recebe um grafo simples (lista de adjacência) alocado dinâmicamente e o destrói. 
    Retorna sempre NULL, para setar o ponteiro. */
t_vertice * destroigrafo(t_vertice grafo[], int nvertices);

/*  Recebe um grafo simples (lista de adjacência) e seu número de vértices. 
    Imprime-o na tela.*/
void printgrafo(t_vertice grafo[], int nvertices);

/*  Recebe um grafo simples (lista de adjancência) e o endereço de um vértice inicial. 
    Realiza busca em largura (marca os vértices como visitados). Não possui retorno. */
void bfs(t_vertice grafo[], t_vertice *start);

/*  Realiza o cálculo do número de componentes conexos em um grafo simples (usando bfs),
    dado um grafo (lista de adjacência) e seu número de vérices. 
    Exibe na tela o resultado.
    Não possui retorno. */
void componentesbfs(t_vertice grafo[], int nvertices);

/*  Calcula as distâncias do vértice 0 a todos os demais vértices (usando bfs). 
    Recebe um grafo simples (lista de adjacência) e seu número de vértices.
    Exibe o resultado na tela, conforme a especificação. Não possui retorno. */
void distanciasbfs(t_vertice grafo[], int nvertices);

/*  Realiza dfs em um grafo simples. Recebe o grafo e o endereço de um vértice inicial.
    Não possui retorno. */
void dfs(t_vertice grafo[], t_vertice *start);

/*  Recebe um grafo simples (grafo - lista de adjacência) e seu número de vértices. 
    Calcula as distâncias do vértice 0 a todos os demais vértices (usando dfs. 
    Exibe o resultado na tela. Não possui retorno. */
void distanciasdfs(t_vertice grafo[], int nvertices);

/*  Recebe um grafo simples (lista de adjacência) e seu número de vértices. Calcula o número
    de componentes conexos do grafo (usando dfs) e exibe o resultado na tela. Não possui retorno. */
void componentesdfs(t_vertice grafo[], int nvertices);

#endif