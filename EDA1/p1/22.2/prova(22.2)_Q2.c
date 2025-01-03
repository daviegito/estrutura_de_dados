#include <stdio.h>
char * acheSobrenome(char nome[]){
    char *pnome;
    int i = 0;
    while (nome[i] != ' ')
    {
        i++; //ele vai iterando pela palavra até achar algum espaço
    }
    i++; // para pular o espaço e ir pra primeira letra do sobrenome
    pnome = &nome[i]; // aqui ele vai apontar para o endereço da primeira letra do sobrenome
    return pnome; //retorna o endereço do sobrenome
}
int main(void){
    char nomeCompleto[80];
    char *p;
    puts("Entre com seu nome e sobrenome"); //puts é usado para imprimir strings como o printf
    fgets(nomeCompleto, sizeof(nomeCompleto), stdin); //pega a string até o \n
    p = acheSobrenome(nomeCompleto);
    puts(p); //usado para pegar a string de p até o final/NULL/EOF
    return 0;
}