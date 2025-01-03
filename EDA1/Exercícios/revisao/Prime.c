#include <stdio.h>

int main()
{
    //declarar variavel
    int numero; 
    int cont_divisores; //Contar os divisores
    int i;
    //guardar variavel
    printf("Digite um número para verificarmos se ele é primo ou não: \n");
    scanf("%d", &numero);
    cont_divisores = 0;
    for (i = numero; i >= 1; i--) {
        if(numero % i == 0) {
            //Se i for divisor de numero
            //Incrementa-se a contagem de divisores
            cont_divisores++;
        }
    }
    if (cont_divisores == 2) {
        printf("O número é primo.\n");
    } else {
        printf("O número não é primo.\n");
    }

    return 0;
}
