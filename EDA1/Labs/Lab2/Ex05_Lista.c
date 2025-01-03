/*Dado um vetor de inteiros e o seu número de elementos, 
faça uma função recursiva que inverta a posição dos seus elementos.*/

#include <stdio.h>
#include <stdlib.h>

void inverte(int *vetor, int n, int i){
    if(i < n/2){
        int aux = vetor[i];
        vetor[i] = vetor[n-i-1];
        vetor[n-i-1] = aux;
        inverte(vetor, n, i+1);
    }
}

int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = (int *)malloc(n*sizeof(int));
    printf("Digite os elementos do vetor: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    inverte(vetor, n, 0);
    printf("Vetor invertido: ");
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
}