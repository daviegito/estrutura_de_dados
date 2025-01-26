//programa de busca binária que procura um valor que coincida
//com o valor da chave inicial (" "), index 1
//na primeira interação, sai g / pcont = 1
//na segunda, sai a / pcont = 2
//na terceira, sai " " / pcont = 3
#include <stdio.h>

//inicio = 0 / meio = 'd' que é 13 / fim = 27 / chave = 'a' que é 1 
int Q3(char *nome, int tamanho, int matricula){
    int inicio = 0, meio, fim = tamanho -1, pcont = 0;
    char chave = nome[matricula%10];
    while(inicio<=fim){
        pcont++;
        meio = (inicio+fim)/2;
        if(chave == nome[meio]) break;
        else if (chave < nome[meio]) fim = meio-1;
        else inicio = meio + 1;
    }
    return pcont;
}
// qual resultado passando os parametros abaixo?
// letras do seu nome completo em ordem alfabetica e com os espaços no inicio ex. "thales henrique euflauzino dos santos" -> "    aaadeeefhhiillnnnooqrsssstttuuuz"
int main(){
    int res = Q3("    aacddeeeghiilmooooqrstuv", 28, 231030421); // letras do nome em ordem alfabetica com espacos no inicio, n de chars do nome, matricula;
    printf("\n\nresultado = %d\n\n", res);
}