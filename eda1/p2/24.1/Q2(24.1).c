//a chave é a letra correspondente aos 2 últimos dígitos da matrícula
//no caso, 21+1(a inicia em zero) = 22 ("v")
//depois o programa procura v na string antes do espaço
//e retorna a posição. No caso de Davi, "v" está na posic 2.

#include <stdio.h>

char letra(int P)
{
    P = P % 26; //dá 0 e sobra 21
    return 'a' + P; // 'a' + 0 = a;
}
int Q2(char *nc, int matricula)
{
    int p = 0, posic = -1;
    char chave = letra(matricula%100); 
    printf("%d\n", matricula%100);
    while(nc[p] != '\0'){
        if(chave == nc[p])
            posic = p;
        p++;
    }
    return posic;
}
// RESUMO
// RETORNA A POSICAO DO CARACTERE QUE RETORNA APOS A EXECUCAO DO PROCEDIMENTO 'LETRA';

// QUAL RESUTADO PASSANDO NOME COMPLETO E MATRICULA COMO PARAMETROS?

int main(){
    int res = Q2("davi marques do egito coelho", 231030421);
    printf("resposta = %d\n\n", res); 
}