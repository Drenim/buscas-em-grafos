# buscas-em-grafos
  Trabalho da disciplina Teoria de Grafos e Análise Combinatória. O programa efetua a leitura de um grafo (armazenado em um 
arquivo de texto conforme especificação) e possibilita a execução de alguns algoritmos em tal grafo.

## forma de uso:
  Após compilado, o programa deve ser usado da seguinte forma: 
```
  ./main -*algoritmo* -*cálculo* *grafo*
```

## algoritmos disponíveis
  Os algoritmos disponíveis são **busca em largura** (opcção *-bfs*) e **busca em profundidade** (opção *-dfs*).
  
## cálculos disponíveis
  É possível obter o número de componentes conexas do grafo (opção *-c*) e calcular a distância de cada vértice ao vértice 0 
(opção *-d*).

## especificação do arquivo/grafo
  O grafo de entrada é armazenado em um arquivo texto. A primeira linha do arquivo contém dois números *n* e *m*, representando
o número de vértices e arestas do grafo, respectivamente. As próxiams *m* linhas do arquivo apresentam duplas de números da 
forma *i* *j*, representando uma aresta entre os vértices *i* e *j*. A contagem dos vértices começa em zero.
Por exemplo, um grafo completo com cinco vértices é representado da seguinte maneira:
```
  5 10
  0 1
  0 2
  0 3
  0 4
  1 2
  1 3
  1 4
  2 3
  2 4
  3 4
```

## exemplos:
* Obter o número de componentes conexas do grafo *grafo.txt* usando o algoritmo *dfs*. 
```
./main -dfs -c grafo.txt
```
* Calcular as distâncias de todos os vértices do grafo *grafo.txt* ao vértice 0 usando *bfs*.
```
./main -bfs -d grafo.txt
```

