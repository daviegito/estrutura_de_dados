/*Defina a função div que recebe como argumentos dois números naturais  m e  n e devolve o resultado da divisão inteira de  m por  n. 
Você não pode recorrer às operações aritméticas de multiplicação, divisão e resto da divisão inteira.*/

#include <stdio.h>
#include <stdlib.h>

int division(int m, int n){
    if(m < n){
        return 0;
    }
    return 1 + division(m-n, n);
}

int main() {
    int m, n;
    printf("Insira o dividendo: ");
    scanf("%d", &m);
    printf("Insira o divisor: ");
    scanf("%d", &n);
    printf("O resultado da divisão inteira de %d por %d é: %d\n", m, n, division(m, n));
    return 0;
}
