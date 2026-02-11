/*Faça uma função recursiva que verifique se os parênteses de uma expressão aritmética estão balanceados. Sua função deve retornar:
0, caso os parênteses estejam balanceados
-1, caso fique parênteses abertos sem fechar
1, caso tenha mais fecha parênteses do que abre parênteses.*/

#include <stdio.h>
#include <string.h>

// Função recursiva para verificar parênteses balanceados
int ChecaParenteses(const char *expr, int count) {
    // Caso base: Se chegar ao final da string
    if (*expr == '\0') {
        if (count == 0) {
            return 0; // Parênteses balanceados
        } else {
            return -1; // Ficaram parênteses abertos
        }
    }

    // Processa o caractere atual
    if (*expr == '(') {
        count++;
    } else if (*expr == ')') {
        count--;
        if (count < 0) {
            return 1; // Mais fecha-parênteses do que abre-parênteses
        }
    }

    // Continua para o próximo caractere
    return ChecaParenteses(expr + 1, count);
}

int main() {
    printf("Digite a expressão abaixo:\n"); 
    scanf("%s", expression1);
    char *expr;
    expr = expression1;
    printf("%d\n", ChecaParenteses(expr, 0));
    return 0;
}