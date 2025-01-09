/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

//Ordenar um vetor de caracteres
int separa (char v[], int p, int r) {
    int c = v[r]; // pivô
    int t, j = p;
    for (int k = p; k < r; ++k)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            ++j;
        }
    t = v[j], v[j] = v[r], v[r] = t;
    return j;
}

//Extrair quantas trocas de elemento foram feitas
void quicksort (char v[], int p, int r, long int *qt_trocas){
   long int i=0;
   if (p < r) {
      int j = separa (v, p, r);
      quicksort (v, p, j-1, qt_trocas);
      quicksort (v, j+1, r, qt_trocas);
    } 
    qt_trocas = &i;
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