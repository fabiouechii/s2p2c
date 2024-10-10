#include <stdio.h>

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
    int tit;
    int ini;
    int deadline;
    int percent;
    printf("\nTITULO:");
    scanf("%d", &tit);
    printf"\nDATA DE INICIO:");
    scanf("%d", &ini);
    printf"\nDATA DE ENCERRAMENTO:");
    scanf("%d", &deadline);
    printf"\n POR CENTAGEM FEITA:");
    scanf("%d", &percent);
}

int edit(){
    printf("edit");
}

int main(){
    menu();
    return 0;
}