/*Um vetor s é sufixo de um vetor w se s for um segmento do fim de  w. 
Faça a função recursiva sufixoQ que recebe como argumentos dois vetores de inteiros s e w e devolva 1 se  s for sufixo de w ou 0 em caso contrário.*/

#include <stdio.h>
#include <stdlib.h>

int sufixoQ(int *s, int *w, int tamS, int tamW, int i, int j){
    if(i == tamS){
        return 1;
    }
    if(s[i] == w[j]){
        return sufixoQ(s, w, tamS, tamW, i+1, j+1);
    }
    if(s[i] != w[j]){
        return 0;
    }
}
//Dúvidas aqui, não sei se está correto
int main() {
    int s[5] = {1, 2, 3, 4, 5};
    int w[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    if(sufixoQ(s, w, 5, 10, 0, 5)){
        printf("S é sufixo de W\n");
    } else {
        printf("S não é sufixo de W\n");
    }

    return 0;
}