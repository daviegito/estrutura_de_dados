/*Faça uma função recursiva para intercalar duas palavras V1 e V2 e colocar o resultado em V3. Considere que V3 já está alocado com espaço suficiente para receber os caracteres de V1 e V2.
*/

#include <stdio.h>
#include <stdlib.h>

// Função recursiva para intercalar os elementos de dois vetores char
void IntercalaVetores(char *V1, char *V2, char *V3) {
    int pinc1 = 0, pinc2 = 0; // Variáveis para controlar o incremento de V1 e V2
    if (*V1 == '\0' && *V2 == '\0') { // Caso base: ambos os vetores estão vazios
        *V3 = '\0'; // Termina V3 com o caractere nulo
        return;
    }

    if (*V1 != '\0') { // Se V1 ainda tem elementos
        *V3 = *V1; // Coloca o caractere atual de V1 em V3
        V3++; // Incrementa o ponteiro de V3    
        pinc1 = 1;
    }

    if (*V2 != '\0') { // Se V2 ainda tem elementos
        *V3 = *V2; // Coloca o caractere atual de V2 em V3
        V3++; // Incrementa o ponteiro de V3
        pinc2 = 1;
    }
    IntercalaVetores(V1 + pinc1, V2 + pinc2, V3); // Chama a função recursivamente com o resto de V2
}

int main() {
    int n; // Tamanho dos vetores
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);
    char V1 = (char *) malloc(n * sizeof(char));
    char V2 = (char *) malloc(n * sizeof(char));
    char V3[sizeof(V1) + sizeof(V2) - 1]; // -1 para o caractere nulo
    printf("Digite a primeira palavra: ");
    scanf("%s", V1);
    printf("Digite a segunda palavra: ");
    scanf("%s", V2);
    IntercalaVetores(V1, V2, V3);  
    printf("Intercalacao: %s\n", V3); 
    return 0;
}