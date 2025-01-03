/*Leia um código de município e mostre na tela as seguintes
informações deste município: Município, UF. Região, População
em 2010 e Porte. Mostre ainda o tempo de execução desta busca
com Busca Binária e Busca Sequencial.*/

#include <stdio.h>
#include <stdlib.h>

struct municipio {
    char uf[2]; //2 primeiros digitos e colado ao nome do municipio
    char nome[100]; //nome do municipio
    int codigo; //codigo do municipio que sera usado na busca 
    char regiao[20]; //regiao do municipio
    int populacao; //populacao do municipio em 2010
    char porte[20]; //porte do municipio
};

void informacoes(struct municipio *m){
  FILE *dados; 
  struct municipio mun;
  dados = fopen("ibge.csv", "r");
   if (dados != NULL){
      char linha[300];
      fscanf(dados, "%[^\n]\n", linha);
      while (!feof(dados)) {
        //verificar se o primeiro dado, da UF, sera registrado de maneira correta
        fscanf (dados, "%[2], %[^;], %d, %[^;], %d, %[^;]\n", 
        mun.uf, 
        mun.nome, 
        &mun.codigo, 
        mun.regiao, 
        &mun.populacao, 
        mun.porte);
        //leitura dos dados que serao preenchidos da struct
        printf("Municipio: %s\n", mun.nome);
        printf("UF: %s\n", mun.uf);
        printf("Regiao: %s\n", mun.regiao);
        printf("Populacao em 2010: %d\n", mun.populacao);
        printf("Porte: %s\n", mun.porte);
      }
      fclose(dados);
   } else {
      printf("Erro ao abrir o arquivo\n"); 
   }
}

int buscaBinaria(int *V, int n, int chave){
  int p, inicio, final, meio;
  inicio = 0;
  final = n - 1;
  while(inicio <= final){
    meio = (inicio + final)/2;
    if (chave == V[meio])
    return meio;
    if (chave < V[meio])
    final = meio - 1://busca nos valores menores
    else
    inicio = meio + 1;//busca nos valores maiores
  }
  return -1; //chave não encontrada
}

int main () {
    BuscaIBGE();
    informacoes();
    return 0;
}