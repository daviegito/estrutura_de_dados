/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int separa(char v[], int p, int r, long int *qt_trocas) {
    char c = v[r];
    int i = p;
    
    for(int j = p; j < r; j++) {
        if(v[j] <= c) {
            char temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            (*qt_trocas)++; //incrementa a contagem de trocas
            i++;
        }
    }
    
    char temp = v[i];
    v[i] = v[r];
    v[r] = temp;
    (*qt_trocas)++; //incrementa para a troca do pivô
    
    return i;
}

//Extrair quantas trocas de elemento foram feitas
void quicksort (char v[], int p, int r, long int *qt_trocas){
   if (p < r) {
      int j = separa (v, p, r, qt_trocas);
      quicksort (v, p, j-1, qt_trocas);
      quicksort (v, j+1, r, qt_trocas);
    } 
}

int main() {
    char v[1024];
    long int qt_trocas = 0;
    int n;
    if (fgets(v, sizeof(v), stdin) != NULL) {
        v[strcspn(v, "\n")] = '\0'; // Remove a nova linha, se existir
    }
    n = strlen(v);  // Obtém o tamanho do vetor de caracteres
    printf("Antes : %s\n", v);
    quicksort(v, 0, n - 1, &qt_trocas);
    printf("Depois: %s\n", v);
    printf("Trocas: %ld\n", qt_trocas);
    return 0;
}