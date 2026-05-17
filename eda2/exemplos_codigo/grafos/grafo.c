struct Grafo {
  int n;
  int **matriz;
};

Grafo* criarGrafo(int n) {
Grafo *g = malloc(sizeof(Grafo));
g->n = n;
g->matriz = malloc(n * sizeof(int*));
for (int i = 0; i < n; i++) {
g->matriz[i] = malloc(n * sizeof(int));
for (int j = 0; j < n; j++)
g->matriz[i][j] = 0;
}
return g;
}

void inserirAresta(Grafo *g, int u, int v) {
  g->matriz[u][v] = 1;
  g->matriz[v][u] = 1;
}

void removerAresta(Grafo *g, int u, int v) {
  g->matriz[u][v] = 0;
  g->matriz[v][u] = 0;
}

void imprimirGrafo(Grafo *g) {
  for (int i = 0; i < g->n; i++) {
    for (int j = 0; j < g->n; j++) {
      printf("%d ", g->matriz[i][j]);
    }
    printf("\n");
  }
}


