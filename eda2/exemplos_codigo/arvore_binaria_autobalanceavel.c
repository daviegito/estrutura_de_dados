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

celula *insere_rne(celula *raiz, int x) {
  if (raiz != NULL){
    //operação de busca
    if (x<raiz->dado)
      raiz->esq = insere_rne(raiz->esq,x);
    else if (x>raiz->dado)
      raiz->dir = insere_rne(raiz->dir,x);
    //operações de correção caso haja desbalanço
    if (ehPreto(raiz->esq) && ehVermelho(raiz->dir))
      raiz = rotacao_a_esquerda(raiz);
    if (ehPreto(raiz) && ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
      raiz = rotacao_a_direita(raiz);
    if (ehPreto(raiz) && ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
      sobe_cor(raiz);
    return raiz; //volta caso a raiz mude com alguma operação de correção
  }
  else {
    celula *novo = malloc(sizeof(celula));
    novo -> dado = x;
    novo -> cor = v;
    novo -> esq = novo -> dir = NULL;
    return novo;
  }
}

celula *insere(celula *raiz, int x){
  raiz = insere_rne(raiz,x);
  raiz -> cor = p;
  return raiz;
}
