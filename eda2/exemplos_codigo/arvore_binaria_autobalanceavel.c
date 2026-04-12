#insert <stdio.h>
#insert <stdlib.h>

//Árvores rubro-negras esquerdistas

enum cor {v,p}; //vermelho e preto
typedef struct celula {
  int dado;
  enum cor cor;
  struct celula *esq, *dir;
} celula;

celula *cria_abb(int x) {
  celula *raiz = malloc(sizeof(celula));
  raiz->dado=x;
  raiz->esq=raiz->dir=NULL; //arvore ainda não existe
  raiz->cor=p;
  return raiz;
}
