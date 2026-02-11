#include <stdio.h>
#include <string.h> // Para a função strlen

// Função que ordena os caracteres de uma string em ordem decrescente
void Q2(char *str) {
    int n = strlen(str); // Obtém o comprimento da string
    for (int i = 0; i < n-1; i++) { // Loop externo: percorre cada caractere da string até o penúltimo
        for (int j = i+1; j < n; j++) { // Loop interno: percorre os caracteres à direita de 'i'
            printf("str[j %d]: %c\n", j, str[j]); // Imprime o caractere atual do loop interno
            printf("str[i %d]: %c\n", i, str[i]); // Imprime o caractere atual do loop externo
            if (str[j] > str[i]) { // Se o caractere em 'j' for maior que o caractere em 'i'
                char temp = str[i]; // Armazena o caractere em 'i' em uma variável temporária
                str[i] = str[j]; // Atribui o caractere em 'j' para a posição 'i'
                str[j] = temp; // Atribui o valor armazenado em 'temp' para a posição 'j'
            }    
        }  
    }
}

// Programa principal que testa a função Q2
int main() {
    char str[] = "davi"; // Define uma string de exemplo
    printf("String antes da ordenacao: %s\n", str); // Imprime a string antes da ordenação
    Q2(str); // Chama a função Q2 para ordenar a string
    printf("String depois da ordenacao: %s\n", str); // Imprime a string após a ordenação
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}