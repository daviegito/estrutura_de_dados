#include <stdio.h>
#include <stdlib.h>

// Função Q5 que escreve uma string em um arquivo várias vezes e retorna o tamanho do arquivo
long Q5(char *NC, int R) {
    long r;
    FILE *A = fopen("Saida.txt", "w"); // Abre o arquivo "Saida.txt" para escrita
    for (int i = 0; i < R; i++) {
        fprintf(A, "%s", NC); // Escreve a string NC no arquivo R vezes
    }
    fclose(A); // Fecha o arquivo após a escrita

    A = fopen("Saida.txt", "r"); // Reabre o arquivo "Saida.txt" para leitura
    fseek(A, 0, SEEK_END); // Move o ponteiro do arquivo para o final
    r = ftell(A); // Obtém a posição atual do ponteiro do arquivo (tamanho do arquivo)
    fclose(A); // Fecha o arquivo
    // remove("Saida.txt"); // Opcional: remove o arquivo "Saida.txt"
    return r; // Retorna o tamanho do arquivo
}

// Função principal que testa a função Q5
int main() {
    char nc[] = "thales henrique euflauzino dos santos"; // Nome completo em letras minúsculas
    int R = 11; // Valor de R (último dígito da matrícula acrescido de 3)
    long r = Q5(nc, R); // Chama a função Q5 com o nome completo e R
    printf("resultado: %ld \n", r); // Imprime o resultado (tamanho do arquivo)
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}