#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *esq, *dir;
} celula;

celula *cria_abb(int x) {
  celula *raiz = malloc(sizeof(celula));
  raiz -> esq = raiz -> dir = NULL;
  raiz -> dado = x;
  return raiz;
}


