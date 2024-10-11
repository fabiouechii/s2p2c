#include <stdio.h>
#include <string.h>

int menu();
int lista();
int edit();
int novo();

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
}

//---------------------------------------------------------------------------------------

int lista(){
    printf("lista");
    return 0;
}
    
int novo(){
    char lista[4][100];
    char tit[100];
    char ini[100];
    char deadline[100];
    char percent[100];
    printf("\nTITULO:");
    scanf(" %[^\n]", tit);
    strcpy(lista[0],tit);
    printf("\nDATA DE INICIO:");
    scanf(" %[^\n]", ini);
    strcpy(lista[1],ini);
    printf("\nDATA DE ENCERRAMENTO:");
    scanf(" %[^\n]", deadline);
    strcpy(lista[2],deadline);
    printf("\n POR CENTAGEM FEITA:");
    scanf(" %[^\n]", percent);
    strcpy(lista[3],percent);
    for (int i = 0; i < 4; i++) {
        printf("lista[%d]: %s\n", i, lista[i]);
    }
}

int edit(){
    printf("edit");
}

int main(){
    menu();
    return 0;
}
