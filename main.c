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

int lista(const char* arq){
    FILE *file = fopen(arq, "rb");
    if (!file) {
        printf("erro\n");
        return -1;
    }

    tarefa c;
    int index = 0;
    printf("Lista de Tarefas:\n");
    while (fread(&c, sizeof(tarefa), 1, file) == 1) {
        printf("%d. Titulo: %s, Data de Inicio: %s, Data de Encerramento: %s, Porcentagem: %s\n",
            index+1, c.titulo, c.data_inicio, c.data_encerramento, c.porcentagem);
        index++;
    }
    
    fclose(file);
    menu();
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
        menu();
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
