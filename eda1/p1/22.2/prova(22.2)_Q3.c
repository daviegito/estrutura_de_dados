#include <stdio.h>
#include <stdlib.h>

float Media(float *pV, int pn){
    float pM = 0;
    int pInd;
    for (pInd = 0; pInd<pn; pInd++)
    {
        pM += pV[pInd]; // Soma o valor do vetor
    }
    return (pM/pn); // Retorna a média
}
float Media2(float *pV, int pn){
    float pM = 0, *pVaux = pV;
    int pInd;
    for (pInd = 0; pInd<pn; pInd++)
    {
        pM += *pVaux; // Soma o valor do ponteiro
        pVaux++; // Avança o ponteiro
    }
    return (pM/pn); // Retorna a média
}
int main(void) {
    float vetor[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    
    printf("Media (Media): %.2f\n", Media(vetor, 5));
    printf("Media (Media2): %.2f\n", Media2(vetor, 5));
    
    return 0;
}

//Resposta correta letra e: Media e Media2 estão corretas e pV pode ser um vetor estático ou dinâmico.