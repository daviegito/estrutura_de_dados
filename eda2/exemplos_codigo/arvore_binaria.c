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

celula *cria_abb(int x) {
  celula *raiz = malloc(sizeof(celula));
  raiz -> esq = raiz -> dir = NULL;
  raiz -> dado = x; //x é o que quer se inserir na árvore
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
      raiz->esq = inserir(raiz->esq,x); //valores menores à esquerda
    else if(x>raiz->dado)
      raiz->dir = inserir(raiz->dir,x); //valores maiores à direita
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

int main() {
  return 0;
}
