/* Fazer uma função de Ackermann */ 
#include <stdio.h>
#include <stdlib.h>

int AckermannRecursivo(int m, int n) {
  if (m == 0) {
    return n + 1;
  } else if (m > 0 && n == 0) {
    return AckermannRecursivo(m - 1, 1);
  } else if (m > 0 && n > 0) {
    return AckermannRecursivo(m - 1, AckermannRecursivo(m, n - 1));
  }
}
// Não roda se os números forem muito grandes pq o scanf fica meio travado - consertar isso.
int main () {
  int m;
  int n;
  do {
    printf("Digite um valor inteiro positivo para m: ");
    scanf("%d", &m);
  } while (m < 0);
  do {
    printf("Digite um valor inteiro positivo para n: ");
    scanf("%d", &n);
  } while (n < 0);
  printf("O resultado da função de Ackermann é: %d\n", AckermannRecursivo(m, n));
  return 0;
}