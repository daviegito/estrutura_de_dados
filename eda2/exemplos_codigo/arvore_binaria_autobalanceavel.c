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
  Fp *f = malloc(sizeof(Fp));
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

int extrai_maximo(Fp *f){
// se n = 0, a função pode não retornar nada, então seria bom uma flag que desse 0 ou 1 a depender se n = 0
  if(f->n>0){
    int max = f -> dado[0];
    f->dado[0] = f->dado[f->n-1];
    f->n--;
    desce_no_heap(f,0);
    return max;
  }
}

void desce_no_heap(Fp *f,int k){
  int esq = 2*k+1;
  if(esq<f->n){
    int maior_filho=esq;
    int dir = esq+1;
    if(dir<f->n && f->dado[dir]>f->dado[esq])
      maior_filho=dir;
    if(f->dado[k]<f->dado[maior_filho]){
      troca(&f->dado[k], &f->dado[maior_filho]);
    desce_no_heap(f,maior_filho);
    }
  }
}

// Hash

typedef struct celula{ //inclui as informações dos objetos
  int chave;
  struct celula *prox;
} celula;

typedef struct {
  celula **tab; //a tabela será um vetor de ponteiros
  int m;
} hash;

hash *cria_hash(int m){
  hash *h = malloc(sizeof(hash));
  h->m=m;
  h->tab=malloc(sizeof)
  for(int i=0;i<m;i++){
    h->tab[i]=malloc(sizeof(celula));
    h->tab[i]->prox=NULL;
  }
  return h;
}

void destroi_hash(hash *h){
  for(int i=0; i<h->m;i++) destroi_lista(h->tab[i]); //recebe uma lista encadeada com nó na cabeça e desaloca todos os nós
  free(h->tab);
  free(h);
}

void inserir(hash *h, int ch){
  int pos = fhash(h, ch);
  inserir_lista(h->tab[pos],ch); //Insere ch na lista encadeada, mas antes verifica se já não está na lista
}

int fhash(hash *h, int ch){
  return ch%h->m;
}
