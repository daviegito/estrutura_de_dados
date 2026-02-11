#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int particiona(int *V, int inicio, int fim) {
    int pivo = (V[inicio] + V[fim] + V[(inicio+fim)/2])/3;
    while(inicio<fim) {
        while(inicio < fim && V[inicio] <= pivo)
            inicio = inicio + 1; //primeira metade
        while(inicio < fim && V[fim] > pivo)
            fim = fim - 1; //segunda metade
        int aux = V[inicio];
        V[inicio] = V[fim];
        V[fim] = aux;
    }
    return inicio;
}

void quickSort(int *V, int inicio, int fim) {
    if(inicio < fim) {
        int pos = particiona(V, inicio, fim);
        quickSort(V, inicio, pos-1); //elementos à esquerda - menores elementos
        quickSort(V, pos, fim); //elementos à direita - maiores elementos
    }
}

void imprimir(int *V, int tam){
    int i;
    for(i = 0; i <= tam; i++) {
        printf("%d", "", V[i]);
    printf("\n");
    }
}

int main() {
    int tamanho;
    printf("Digite o número de elementos: ");
    scanf("%d", &tamanho);

    int V[tamanho];
    printf("Digite os elementos: ");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &V[i]);
    }

    quickSort(V, 0, tamanho - 1);

    printf("O vetor ordenado é: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
    return 0;
}

