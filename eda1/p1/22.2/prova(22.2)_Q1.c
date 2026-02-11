#include <stdio.h>

int main(void){
    int vet[]= {10,20,30};
    int *p = vet;
    p++; //p inicialmente aponta para vet[0], p++ faz p apontar para vet[1]
    printf("\n%d", *p); //*p desreferencia p, ou seja, p aponta para vet[1], 20.
    (*p)++; //Desreferencia p e incrementa o valor de vet[1] em 1 = 21.
    printf("\ - %d", *p); //*p agora acessa vet[1], que vale 21.
    printf("\ - %d", (*p+1)); //calcula o valor de vet[1] + 1 = 22.
    return 0; //no final, o programa imprime 20 - 21 - 22.
}