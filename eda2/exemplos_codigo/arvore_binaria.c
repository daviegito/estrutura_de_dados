#include <stdio.h>
#include <stdlib.h>

//Implementação da AB
typedef struct celula {
  int dado;
  struct celula *esq, *dir; //subárvores esquerda e direita
} celula;
 
/* RECURSÃO */

void preordem (celular *raiz) {
  if (raiz != NULL) {
    printf ("%d", raiz -> dado); //raiz vem antes
    preordem (raiz -> esq);
    preordem (raiz -> dir);
  }
}

void emordem (celular *raiz) {
  if (raiz != NULL) {
    emordem (raiz -> esq);
    printf ("%d", raiz -> dado); //esquerda vem antes da raiz
    emordem (raiz -> dir);
  }
}

void posordem (celular *raiz) {
  if (raiz != NULL) {
    posordem (raiz -> esq);
    posordem (raiz -> dir);
    printf ("%d", raiz -> dado); //raiz vem após esquerda e direita
  }
}

/* SEM RECURSÃO */

/* 
void cria_pilha () {

}

void empilha () {

}

void desempilha () {

}

void destroi.pilha () {
//Verificar se é possível nomear a função assim mesmo
}

*/

void preordem (celula *raiz) {
  pilha *p = cria_pilha(); //somente possível com pilha
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

/*
void cria_fila () {

}

void enfileira () {

}

void desenfileira () {

}

void destroi_fila () {
//ver se seria possível
}
*/

void largura(celula *raiz){
  fila *f = cria_fila();
  enfileira(f, raiz);
  while(!fila_vazia(f)) {
    raiz = desenfileira(f);
    printf("%d", raiz->dado);
    if (raiz -> esq != NULL)
      enfileira(f, raiz->esq); //já que não está nula
    if (raiz -> dir != NULL)
      enfileira(f, raiz->dir); //já que não está nula
  }
  destroi_fila(f);
}

//Usa recursos pós-ordem
int altura(celula *raiz) {
  if (raiz != NULL) {
    int he = altura (raiz->esq); //he = altura esquerda
    int hd = altura (raiz->dir); //hd = altura direita
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
