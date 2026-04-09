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

celula *buscar(celula *raiz, int x) {
  if(raiz != NULL) {
    if(x < raiz->dado)
      return buscar(raiz->esq,x);
    else if(x>raiz->dado)
      return buscar(raiz->dir,x);
    else
      return raiz;
  }
  else
    return NULL;
}

celula *inserir(celula *raiz, int x) {
  if(raiz!=NULL) {
    if(x<raiz->dado)
      raiz->esq = inserir(raiz->esq,x);
    else if(x>raiz->dado)
      raiz->dir = inserir(raiz->dir,x);
    return raiz;
  } else {
    return cria_abb(x);
  }
}

celula *remover(celula *raiz, int x) {
  if(raiz != NULL) {
    if(x<raiz->dado)
      raiz->esq = remover(raiz->esq,x);
    else if(x>raiz->dado)
      raiz->dir = remover(raiz->dir,x);
    else if(raiz->esq == NULL)
      return raiz->dir;
    else if(raiz->dir == NULL)
      return raiz->esq;
    else 
      remove_sucessor(raiz);
  }
  return raiz;
}

void remove_sucessor(celula *raiz) {
  celula *filho = raiz->dir, pai=raiz;
  while(filho->esq != NULL) {
    raiz = filho;
    filho = filho->esq;
  }
  //Neste ponto, filho aponta para o sucessor da raiz 
  int tmp = raiz -> dado;
  raiz -> dado = filho -> dado;
  filho -> dado = tmp;
  if(pai == raiz)
    pai -> dir = filho -> dir;
  else 
    pai -> esq = filho -> dir;
  free(filho);
}

/*
void remove_antecessor(celula *raiz) {

}
*/  

void destroi_abb(celula *raiz) {
// Pós-ordem é como melhor funciona 
  if (raiz != NULL) {
    destroi_abb(raiz->esq);
    destroi_abb(raiz->dir);
    free(raiz);
  }
}
