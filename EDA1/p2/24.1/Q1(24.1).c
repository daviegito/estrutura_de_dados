#include <stdio.h>
#include <stdlib.h>

int Q1(char *Nome, int qtde) {
    int pc=0;
    if (*Nome == '\0')
        return qtde;
    while (Nome[pc] != '\0'){
        pc++;
    return Q1(Nome+1, qtde+pc);
    }
}
//Retorna a letra minúscula do alfabeto correspondente a posição P
// Letra 'a' corresponde a P = 0, letra 'z' corresponde a P = 25
char letraCorrespondente(int P){
    P = P % 26;
    return 'a' + P; 
}

int main(){
    int res = Q1("Coelho", 0);
    printf("resposta = %d\n", res); 
}