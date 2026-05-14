#ifndef GRAFO_H
#define GRAFO_H

typedef struct Grafo Grafo;

Grafo* criarGrafo(int n);

void inserirAresta(Grafo *g, int u, int v);
void removerAresta(Grafo *g, int u, int v);
void imprimirGrafo(Grafo *g);
void destruirGrafo(Grafo *g);

#endif
