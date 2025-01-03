/*Faça uma função recursiva chamada MediaDig que receba como argumento um número natural e devolva a média dos seus dígitos.
Para fins de cálculos por recursividade, a função usa dois parâmetros extras inicialmente nulos: o tamanho do número e a soma dos dígitos.
O primeiro dígito zero também deve contar para a soma e média*/

#include <stdio.h>
#include <stdlib.h>

float MediaDig(int Numero, unsigned int Tamanho, float Soma){
    if(Numero > 10){
        return MediaDig(Numero/10, Tamanho+1, Soma + Numero%10);
    }
    else{
        Soma += Numero;
        return Soma/(Tamanho+1);
    }
}

int main(){
    int Numero;
    unsigned int Tamanho = 0;
    float Soma = 0;
    printf("Digite um número:\n");
    scanf("%d", &Numero);
    printf("Media dos digitos: %.2f\n", MediaDig(Numero, Tamanho, Soma));
    return 0;
}