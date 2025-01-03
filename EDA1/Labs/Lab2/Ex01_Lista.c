/* Dado um vetor de números reais e o seu número de elementos, fazer uma função recursiva que calcula 
a média dos elementos do vetor*/

#include <stdio.h>
#include <stdlib.h>

float media(float *vetor, int n){
    if(n == 1){
        return vetor[0];
    }else{
        return (vetor[n-1] + media(vetor, n-1));
    }
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    float *vetor = (float *) malloc(n * sizeof(float));
    for(int i = 0; i < n; i++){
        printf("Digite o valor da posicao %d: ", i);
        scanf("%f", &vetor[i]);
    }
    printf("A media dos elementos do vetor eh: %.2f\n", media(vetor, n)/n);
    free(vetor);
    return 0;
}