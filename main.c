#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADgrafo.h"

/*A main recebe por linha de comando os seguintes argumentos, em ordem:
    -algoritmo  (algoritmo a ser excutado: bfs/dfs)
    -operação   (operação a ser realizada no grafo. c para cálculo de co
                 ponentes conexos e d para distâncias em relação ao vértice 0)
    -grafo      (caminho para o arquivo .in onde está o grafo). */

/*   
    AUTOR: Daniel Matos de Castro
    NÚMERO DE MATRÌCULA: 00281955 
*/

int main(int argc, char *argv[]){
    int nvertices;
    FILE *arquivo;
    char *nomearq; 
    t_vertice *grafo;

    if (argc < 4)
        return EXIT_FAILURE;    

    arquivo = fopen(argv[3], "r"); 
    if (arquivo == NULL) exit(EXIT_FAILURE);

    grafo = constroigrafo(arquivo, &nvertices); 
    fclose(arquivo); 

    if (strcmp(argv[1], "-bfs") == 0 && strcmp(argv[2], "-d") == 0){
        distanciasbfs(grafo, nvertices);
    }else{
        if (strcmp(argv[1], "-bfs") == 0 && strcmp(argv[2], "-c") == 0){
            componentesbfs(grafo, nvertices);
        }else{
            if (strcmp(argv[1], "-dfs") == 0 && strcmp(argv[2], "-d") == 0){;
                distanciasdfs(grafo, nvertices);
            }else{
                if (strcmp(argv[1], "-dfs") == 0 && strcmp(argv[2], "-c") == 0){
                    componentesdfs(grafo, nvertices);
                }else{
                    return EXIT_FAILURE;
                }
            }
        }
    }
    grafo = destroigrafo(grafo, nvertices);

    return EXIT_SUCCESS;
}
