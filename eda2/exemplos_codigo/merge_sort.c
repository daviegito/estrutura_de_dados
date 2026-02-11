#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *V, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *)malloc(tamanho*sizeof(int));
    if(temp != NULL) {
        for(i=0; i<tamanho; i++) {
            if(!fim1 && !fim2) {
                if(V[p1] < V[p2])
                    temp[i] = V[p1++]; //combinar ordenado
                 else
                    temp[i]=V[p2++]; //combinar ordenado

                if(p1>meio) fim1=1; //se o vetor acabar, não precisa mais
                //comparar
                if(p2>fim) fim2=1;
        } else {
                if(!fim1) temp[i]=V[p1++]; //copia o que sobrar
                else temp[i]=V[p2++]; //copia o que sobrar
            }
        }
        for(j=0,k=inicio;j<tamanho;j++,k++) //copiar do auxiliar ao original
            V[k]=temp[j];
    }
    free(temp);
}

void mergeSort(int *V, int inicio, int fim) {
    //V é um vetor de números e inicio e fim representam as respectivas partes
    //desse vetor
    int meio;
    if(inicio < fim) {
        meio = floor((inicio+fim)/2); //O meio está na metade entre o início e
        //fim
        mergeSort(V,inicio,meio); //1 das metades
        mergeSort(V,meio+1,fim); //a outra metade
        merge(V,inicio,meio,fim); //combina as 2 metades
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

    mergeSort(V, 0, tamanho - 1);

    printf("O vetor ordenado é: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
    return 0;
}
