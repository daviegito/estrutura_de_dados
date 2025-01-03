/******************************************************************************
Implemente um menu com três opções: C - Fahrenheit para
Celsius, F - Celsius para Fahrenheit e S - Sair. Depois que o
usuário optar por uma das duas primeiras opções, leia um valor
float e mostre seu valor na respectiva escala. Caso o usuário
opte pela opção S, encerre o programa.
*******************************************************************************/
#include <stdio.h>

int main()
{
    printf("\n*** Ola, seja bem-vindo a calculadora de temperatura! ***\n");
    char opcao;
    do {
        printf("\nDigite abaixo C para mostrar um valor Fahrenheit em Celsius\nDigite F para mostrar um valor Celsius em Fahrenheit\nDigite S para sair\n");
        scanf(" %c", &opcao);
        if (opcao == 'C') {
            float f_1;
            float c_1;
            printf("Digite um valor em Fahrenheit para ser convertido em Celsius:\n");
            scanf("%f", &f_1);
            printf("O valor em Celsius é %f\n", (f_1 - 32)/9*5);
        } if (opcao == 'F') {
            float f_2;
            float c_2;
            printf("Digite um valor em Celsius para ser convertido em Fahrenheit:\n");
            scanf("%f", &c_2);
            printf("O valor em Fahrenheit é %f\n", (c_2/5 * 9) + 32);
        } if (opcao == 'S') {
            break;
        } if (opcao != 'S' || 'C' || 'F') {
            printf("\n*** Lembre-se que so ha 3 opcoes: C, F ou S, que deverao estar em maiusculo! ***\n");
        }
    } while (opcao != 'S');
    return 0;
}