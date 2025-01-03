#include <stdio.h>
#include <stdlib.h> // Para usar malloc
#include <locale.h>

char *Q3(int *M, char *NC) {
    char *code = (char*) malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++) {
        code[i] = NC[M[i]]; //o i vai aumentando gradativamente e com isso m vai pegando o mesmo índice
        //do número de matrícula [i=0 / m[0] = 2/ NC[2] = 'v' / code[0] = 'v']
        if (code[i] == ' ') {
            code[i] = '-'; //substitui espaço por hífen
        }
    }
    return code;
}
// QUAL O RESULTADO RETORNADO PELA FUNCAO Q3 NO CAOS DE VOCE A INVOCAR PASSANDO O CONJUNTO DE PARAMETROS ABAIXO?
// VETOR CONTENDO OS DIGITOS DE SUA MATRICULA EX. 222006178 -> MATRICULA = [2,2,2,0,0,6,1,7,8]
// NC = SEU NOME COMPLETO EM LETRAS MINUSCULAS
int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    int m[] = {2,3,1,0,3,0,4,2,1};
    char nc[] = "davi marques do egito coelho";
    char *result = Q3(m, nc);
    printf("Resultado: %s\n", result); 
    free(result); 
    return 0;
}
