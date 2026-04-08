#include <stdio.h>
#include <stdlib.h>

//Implementação da AB
typedef struct celula {
  int dado;
  struct celula *esq, *dir;
} celula;
 
/* RECURSÃO */

void preordem (celular *raiz) {
  if (raiz != NULL) {
    printf ("%d", raiz -> dado);
    preordem (raiz -> esq);
    preordem (raiz -> dir);
  }
}

void emordem (celular *raiz) {
  if (raiz != NULL) {
    emordem (raiz -> esq);
    printf ("%d", raiz -> dado);
    emordem (raiz -> dir);
  }
}

void posordem (celular *raiz) {
  if (raiz != NULL) {
    posordem (raiz -> esq);
    posordem (raiz -> dir);
    printf ("%d", raiz -> dado);
  }
}

/* SEM RECURSÃO */

void preordem (celula *raiz) {
  pilha *p = cria_pilha();
  while (raiz != NULL) {
    printf("%d", raiz->dado);
    if (raiz -> dir != NULL)
      empilha(raiz -> dir);
    raiz = raiz -> esq;
    if (raiz == NULL)
      raiz = desempilha(p);
  }
  destroi.pilha(p);
}

/*
void emordem (celula *raiz) {
  pilha *p = cria_pilha();
  while (raiz != NULL) {
    printf("%d", raiz->dado);
    if (raiz -> dir != NULL)
      empilha(raiz -> dir);
    raiz = raiz -> esq;
    if (raiz == NULL)
      raiz = desempilha(p);
  }
  destroi.pilha(p);
}

void posordem (celula *raiz) {
  pilha *p = cria_pilha();
  while (raiz != NULL) {
    printf("%d", raiz->dado);
    if (raiz -> dir != NULL)
      empilha(raiz -> dir);
    raiz = raiz -> esq;
    if (raiz == NULL)
      raiz = desempilha(p);
  }
  destroi.pilha(p);
}
*/ 

/* PERCURSO EM LARGURA */

void largura(celula *raiz){
  fila *f = cria_fila();
  enfileira(f, raiz);
  while(!fila_vazia(f)) {
    raiz = desenfileira(f);
    printf("%d", raiz->dado);
    if (raiz -> esq != NULL)
      enfileira(f, raiz->esq);
    if (raiz -> dir != NULL)
      enfileira(f, raiz->dir);
  }
  destroi_fila(f);
}

//Usa recursos pós-ordem
int altura(celula *raiz) {
  if (raiz != NULL) {
    int he = altura (raiz->esq);
    int hd = altura (raiz->dir);
    if (he > hd) return he+1;
    else return hd+1;
  }
  else {
    return -1;
  }
}

int main() {
  return 0;
}
