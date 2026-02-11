/*Defina a função num_perf que recebe como argumento um número inteiro positivo e devolve 1 se esse número for um número perfeito e 0 em caso contrário. 
Um número perfeito é um número natural que é igual à soma de todos os seus divisores próprios, isto é, a soma de todos os divisores excluindo o próprio número.*/

#include <stdio.h>
#include <stdlib.h>

int num_perf(int n){
    int i, soma = 0;
    for(i = 1; i < n; i++){
        if(n % i == 0){
            soma += i;
        }
    }
    if(soma == n){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    if(num_perf(n)){
        printf("O número %d é perfeito.\n", n);
    }else{
        printf("O número %d não é perfeito.\n", n);
    }
    return 0;
}