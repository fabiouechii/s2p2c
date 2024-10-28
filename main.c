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
    //menu();
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


int edit() {
    const char* arq = "tarefas.bin";
    lista(arq); // mostra lista

    int indice;
    printf("\nDigite o indice da tarefa que deseja editar: ");
    scanf("%d", &indice);
    indice=indice-1;

    FILE *file = fopen(arq, "r+b");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    tarefa c;
    fseek(file, indice * sizeof(tarefa), SEEK_SET); // move o ponteiro

    if (fread(&c, sizeof(tarefa), 1, file) != 1) {
        printf("Tarefa não encontrada.\n");
        fclose(file);
        return -1;
    }

    // edicao dos campos
    printf("\nEditando tarefa:\n");
    printf("TITULO (atual: %s): ", c.titulo);
    scanf(" %[^\n]", c.titulo);
    printf("DATA DE INICIO (atual: %s): ", c.data_inicio);
    scanf(" %[^\n]", c.data_inicio);
    printf("DATA DE ENCERRAMENTO (atual: %s): ", c.data_encerramento);
    scanf(" %[^\n]", c.data_encerramento);
    printf("PORCENTAGEM (atual: %s): ", c.porcentagem);
    scanf(" %[^\n]", c.porcentagem);

    // move ponteiro para salvar mudancas
    fseek(file, indice * sizeof(tarefa), SEEK_SET);
    fwrite(&c, sizeof(tarefa), 1, file);

    fclose(file);
    printf("\nTarefa editada com sucesso!\n");
    menu();
}

int main(){
    menu();
    return 0;
}
