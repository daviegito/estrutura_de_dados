#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM_MAX_REGISTROS 100
#define TAM_MAX_MEDIDAS 100
#define TAM_MAX_NOME_CIDADE 20

/*Suponha que você seja um cientista de dados trabalhando em uma empresa de análise climática. Você
precisa analisar as temperaturas diárias de várias cidades ao longo de um período indefinido. As temperaturas
são fornecidas uma por uma e não há um número fixo de dias para análise, o que torna necessário o uso de
alocação dinâmica de memória para armazenar essas temperaturas.*/

//Struct de tipos
struct tipos {
    int qtde_dias;
    int qtde_medidas;
    int vetor_medidas;
    char cidade[TAM_MAX_NOME_CIDADE];
    float temperatura;
};

void menu() {
    printf("\n*** Escolha uma opção entre as seguintes:\n");
    printf("1 - Reset\n"); 
    printf("2 - Inserir medida\n"); 
    printf("3 - Estatística\n"); 
    printf("4 - Sair\n"); 
}

void reset() { /*Esta opção deve: ler a quantidade de dias de registros de temperaturas qtde_dias ,alocar o
vetor de medidas e colocar qtde_medidas igual a zero;*/
    FILE *tipos;
    struct tipos qtde_dias;
    struct tipos qtde_medidas;
    struct tipos vetor_medidas;
          tipos = fopen("tipos.h", "r");
          TTemperaturas *vetor_medidas = (TTemperaturas *) malloc(sizeof(TTemperaturas) * qtde_dias);
          if (tipos.h == NULL) {
            printf("Erro ao abrir o arquivo\n");
            return 1;
          }
          else {
            printf("Você escolheu a opção Reset com sucesso!\n");
            int i; //contador
            int *qtde_dias; //quantidade de dias de registros de temperaturas
            int *qtde_medidas; //quantidade de medidas
            int *vetor_medidas; //vetor de medidas   

          }
          fclose(tipos.h);
}

void inserir_medida() { /*Esta opção deve: ler os dados de uma medida (nome da cidade e temperatura) e
adicionar esta medida ao vetor de temperaturas;*/
    FILE *tipos.h;
    struct tipos cidade;
    struct tipos temperatura;
    int i = 20; //contador
          fopen("tipos.h", "r"); /*talvez tenha de escrever e não somente ler porque terá de add a medida 
          ao vetor de temperatura*/
          scanf("Digite o nome de uma cidade:\n%c", cidade);
          scanf("Digite uma temperatura:\n%f", temperatura);
          if (tipos.h == NULL) {
            printf("Erro ao abrir o arquivo\n");
            return 1;
          }
          else {
            printf("Você escolheu a opção Inserir Medida com sucesso!\n");
            for int i = 0; i < 20; i++ {
              
            }
          }
          fclose(tipos.h);
}

void estatistica() { /*Esta opção deve: mostrar a temperatura média, a menor temperatura (o nome da
cidade e temperatura) e a maior temperatura (o nome da cidade e temperatura);*/
    FILE *tipos.h;
    struct tipos temperatura;
    struct tipos cidade;
          fopen("tipos.h", "r");
          if (tipos.h == NULL) {
            printf("Erro ao abrir o arquivo\n");
            return 1;
          }
          else {
            printf("Você escolheu a opção Estatística com sucesso!\n");

          }
          fclose(tipos.h);
}

void sair() { /*Esta opção deve: Desalocar o vetor medidas e encerrar o programa.*/
    FILE *tipos.h;
          fopen("tipos.h", "r");
          if (tipos.h == NULL) {
            printf("Erro ao abrir o arquivo\n");
            return 1;
          }
          else {
            printf("Você escolheu a opção Sair com sucesso!\n");
          }
          fclose(tipos.h);
}

int main() {
    setlocale(LC_ALL, "Portuguese"); //permite acentos e outros caracteres de Português
    int opcao; //Será a opção que o usuário irá escolher
      do {
          menu();
          opcao = scanf("%d", &opcao);
          if opcao == 1 {
            reset();
          }
          else if opcao == 2 {
            inserir_medida();
          }
          else if opcao == 3 {
            estatistica();
          }
          else if opcao == 4 {
            sair();
          }
          else {
            printf("\n*** Opção inválida! Por favor, escolha outra opção\n");
          }
        } while opcao <= 4;
    return 0;
} 



