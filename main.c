#include <stdio.h>
#include <string.h>

int menu();
int lista();
int edit();
int novo();

#define MAX_SIZE 100

int menu(){
    int opcao;
    printf("Menu\n1. Listar\n2. Criar novo projeto\n3. Editar projeto");
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            lista();
            break;
        case 2:
            novo();
            break;
        case 3:
            edit();
            break;
    }
    return 0;
}

//---------------------------------------------------------------------------------------

int lista(){
    printf("\n\nEsta e a sua lista de tarefas:\n");

    char lista[MAX_SIZE][50];
    int tamanho = 0;

    strcpy(lista[tamanho++], "\nTitulo: Teste nome");
    strcpy(lista[tamanho++], "Data de criacao: 10/10/2024");
    strcpy(lista[tamanho++], "Porcentagem: 80%");

    printf("valor 1: ", lista[1]);

    for(int i = 0; i < tamanho; i++) {
        printf("%s\n", lista[i]);
    }    

    return 0;
}
    
int novo(){
    int tit;
    int ini;
    int deadline;
    int percent;
    printf("\nTITULO:");
    scanf("%d", &tit);
    printf("\nDATA DE INICIO:");
    scanf("%d", &ini);
    printf("\nDATA DE ENCERRAMENTO:");
    scanf("%d", &deadline);
    printf("\nPORCENTAGEM FEITA:");
    scanf("%d", &percent);
}

int edit(){
    printf("edit");
}

int main(){
    menu();
    return 0;
}
