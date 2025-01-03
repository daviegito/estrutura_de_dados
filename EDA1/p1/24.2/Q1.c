#include <stdio.h>
#include <stdlib.h>

// Função que processa um número e retorna a soma dos dígitos ímpares dos últimos 'pn' dígitos
int Q1(long long int valor) {
    int *ptr, *pnumeros, pn = valor % 10, pp, psoma = 0;

    // Se o último dígito (pn) for menor que 2, ajusta pn para 5 - pn
    if (pn < 2) pn = 5 - pn;

    // Aloca memória para armazenar 'pn' inteiros
    pnumeros = (int*) malloc(pn * sizeof(int));
    ptr = pnumeros; // Inicializa o ponteiro ptr para apontar para o início do array alocado

    // Extrai os últimos 'pn' dígitos de 'valor' e armazena no array 'pnumeros'
    for (pp = 0; pp < pn; pp++) {
        *ptr = valor % 10; // Armazena o último dígito de 'valor' no array
        valor = valor / 10; // Remove o último dígito de 'valor'
        ptr++; // Avança o ponteiro para a próxima posição no array
    }

    // Soma os dígitos ímpares armazenados no array 'pnumeros'
    for (pp = 0; pp < pn; pp++) { 
        if (pnumeros[pp] % 2 == 0) { // Verifica se o dígito é ímpar
            psoma = psoma + pnumeros[pp]; // Adiciona o dígito ímpar à soma
        }
    }

    // Libera a memória alocada para o array 'pnumeros'
    free(pnumeros);

    // Retorna a soma dos dígitos ímpares
    return psoma;
}

// Função principal que testa a função Q1 com um número de matrícula
int main() {
    int matricula = 231030421; // Número de matrícula
    int x = Q1(matricula); // Chama a função Q1 com a matrícula e armazena o resultado em 'x'
    printf("o resultado e: %d\n", x); // Imprime o resultado
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}