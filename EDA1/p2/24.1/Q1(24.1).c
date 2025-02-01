//Calcula o comprimento da string. Coelho = 6 letras.
//6+5+4+3+2+1=21

#include <stdio.h>
#include <stdlib.h>

int Q1(char *Nome, int qtde) {
    int pc=0;
    if (*Nome == '\0')
        return qtde;
    while (Nome[pc] != '\0')
        pc++;
    return Q1(Nome+1, qtde+pc);
}

int main(){
    int res = Q1("Coelho", 0);
    printf("resposta = %d\n", res); 
}