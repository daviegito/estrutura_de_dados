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

// --- Heap
typedef struct {
  int *dado; //vetor que representa a árvore
  int n, tam; //n é a quantidade de elementos e o tamanho é do vetor
} Fp;

Fp *cria-fp(int tam){
  Fp *f = malloc(sizeod(Fp));
  f->dado = malloc(sizeof(int)*tam);
  f->n = 0;
  f->tam = tam;
  return f;
}

void destroi-fp(Fp *f) {
  free(f -> dado);
  free(f);
}

void insere(Fp *f, int x) {
  if(f->n >= f -> tam) {
    f->dado = realloc(f->dado,2*f->tam*sizeof(int));
    f->tam*=2;
  }
  f->dado[f->n]=x;
  f->n++;
  sobe_no_heap(f, f->n-1);
}

void sobe_no_heap(Fp *f, int k){
  if(k>0){
    int pai = (k-1)/2;
    if(f->dado[pai]<f->dado[k]){
      troca(&f->dado[pai],f->dado+k);
      sobe_no_heap(f,pai);
    }
  }
}

