#include <stdio.h>
#include <string.h>

int menu();
int lista();
int edit();
void novo(const char* arq);

typedef struct {
    char titulo[100];
    char data_inicio[100];
    char data_encerramento[100];
    char porcentagem[100];
} tarefa;



int menu(){
    int opcao;
    printf("Menu\n1. Listar\n2. Criar novo projeto\n3. Editar projeto");
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            lista("tarefas.bin");
            break;
        case 2:
            novo("tarefas.bin");
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
    
void novo(const char* arq) {
    tarefa c;
    FILE *file = fopen(arq, "ab");

    if (file) {
        printf("\nTITULO: ");
        scanf(" %[^\n]", c.titulo);
        printf("\nDATA DE INICIO: ");
        scanf(" %[^\n]", c.data_inicio);
        printf("\nDATA DE ENCERRAMENTO: ");
        scanf(" %[^\n]", c.data_encerramento);
        printf("\nPORCENTAGEM FEITA: ");
        scanf(" %[^\n]", c.porcentagem);

        fwrite(&c, sizeof(tarefa), 1, file); //escreve no arquivo
        
        fclose(file);
        printf("\nadicionada\n");
    } else {
        printf("\nerro\n");
    }
}

int edit(){
    printf("edit");
}

int main(){
    menu();
    return 0;
}
