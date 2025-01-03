#include <stdio.h>
#include <string.h>

// Função que verifica se um caractere é uma consoante minúscula (exceto 'a', 'e', 'i', 'o', 'u')
int Verifica(char c) {
    return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

// Função recursiva que verifica se o caractere L na posição pos é seguido por uma consoante minúscula
int Q4(char *NC, char L, int pos) {
    // Caso base: se a string estiver vazia ou a posição for inválida, retorna -1
    if (NC[0] == '\0' || pos < 0 || pos >= strlen(NC) - 1) {
        return -1;
    }
    // Verifica se o caractere na posição pos é igual a L e se o próximo caractere é uma consoante minúscula
    if (NC[pos] == L && Verifica(NC[pos + 1])) {
        return pos; // Retorna a posição se a condição for satisfeita
    }
    // Chamada recursiva para verificar a próxima posição
    return Q4(NC, L, pos + 1);
}

// Função principal que testa a função Q4
int main() {
    char nc[] = "thales henrique euflauzino dos santos"; // Nome completo em letras minúsculas
    char L = 's'; // Última letra do último sobrenome
    int pos = 0; // Posição inicial
    int resultado = Q4(nc, L, pos); // Chama a função Q4 com o nome completo, a letra L e a posição inicial
    printf("Resultado: %d\n", resultado); // Imprime o resultado
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
