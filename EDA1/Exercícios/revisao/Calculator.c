/******************************************************************************
Here's a calculator to help you with simples tasks. You might insert two numbers and it will help ye with the result.
*******************************************************************************/

//It must have a menu and use can randomize the number of items.

//It must have a menu and use can randomize the number of items.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char produto[10][15] = {"Arroz", "Feijao", "Macarrao", "Carne", "Frango", "Peixe", "Oleo", "Sal", "Acucar", "Cafe"};
    int indice, i, quant_final, escolha; //o valor inteiro corresponde à posição do produto
    do {
    printf("Você deseja comprar ou adicionar produtos?\nDigite 1 para comprar e 2 para adicionar produtos: ");
    scanf("%d", &escolha);
    if (escolha == 1) {
        printf("Quantos produtos você quer comprar?\n");
        scanf("%d", &quant_final);
        for (i = 0; i < quant_final; i++) {
            indice = rand() % 10;
            printf("Produto %d: %s\n", i+1, produto[indice]);
        }
    } if (escolha == 2) {
        printf("Quantos produtos você quer adicionar?\n");
        scanf("%d", &quant_final);
        for (i = 0; i < quant_final; i++) {
            printf("Digite o nome do produto %d: ", i+1);
            scanf("%s", produto[i]);
        }
    } else {
        break;
    } 
    } while (escolha == 1 || 2);
    return 0;
}