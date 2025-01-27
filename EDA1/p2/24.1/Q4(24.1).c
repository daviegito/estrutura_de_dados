#include <stdio.h>

int faux(char *vet, int tam, int i){
    int j, min = i;
    for(j=i+1; j<tam; j++)
        if(vet[j] < vet[min])
            min = j;
    return min;
}

int Q4(char *vet, int tam){
    int i, min, aux, pcont = 0;
    for (int i = 0; i < tam; i++)
        for (int j = i+1; j < tam; j++){
            min = faux(vet, tam, i);
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
            pcont = pcont + (tam - i);
        }
    return pcont;
}
// Qual o valor de R? 20/10
// Qual o valor de nome? adiv
// Qual tipo de ordenacao da funcao q4? Selection Sort

int main(){
    char nc[] = "davi";
    int res = Q4(nc, 4); // primeiro nome, qtd de letras 1o nome;
    printf("\n\nresposta = %d\n\nnc = %s\n\n", res, nc);
}