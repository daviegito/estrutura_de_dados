#include <stdio.h>
#include "grafo.h"

int main() {
  Grafo *g = criarGrafo(4);
  
  inserirAresta(g, 0, 1);
  inserirAresta(g, 1, 2);
  inserirAresta(g, 1, 3);
  inserirAresta(g, 2, 3);
  
  imprimirGrafo(g);
  
  destruirGrafo(g);
  
  return 0;
}
