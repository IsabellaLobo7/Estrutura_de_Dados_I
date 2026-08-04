#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    int id;
    char descricao[100];
    char responsavel[50];
    int status;
    int ativo;
} Tarefa;


// Abre ou cria o arquivo binário
FILE* abreArquivo(char nomeArquivo[]) {
    FILE* arquivo = fopen(nomeArquivo, "rb+");
    if (!arquivo) {
        arquivo = fopen(nomeArquivo, "wb+");
    }
    if (!arquivo) {
        printf("Falha na abertura do Arquivo!\n");
    }
    return arquivo;
}

int getQuantidadeTotal(FILE* arquivo) {
    fseek(arquivo, 0, SEEK_END);
    return ftell(arquivo) / sizeof(Tarefa);
}

void pausa(){
	printf("\nPressione ENTER para continuar: ");
	getchar();
	getchar();
}

void novaTarefa(FILE* arquivo) {
    Tarefa nova;
    
    nova.id = getQuantidadeTotal(arquivo) + 1;
    
    printf("\n=== NOVA TAREFA (ID: %d) ===\n", nova.id);
    
    printf("Informe a Descricao: ");
    scanf(" %[^\n]", nova.descricao);
    
    printf("Informe o Responsavel: ");
    scanf(" %[^\n]", nova.responsavel);
    
    nova.status = 0;
    nova.ativo = 1;
    
    fseek(arquivo, 0, SEEK_END);
    fwrite(&nova, sizeof(Tarefa), 1, arquivo);
    fflush(arquivo);
    
    printf("\nTarefa cadastrada com sucesso!");
    pausa();
}

void listarTarefas(FILE* arquivo) {
    int totalRegistros = getQuantidadeTotal(arquivo);
    if (totalRegistros == 0) {
        printf("\nNenhuma tarefa cadastrada. Pressione ENTER...");
        return;
    }
    Tarefa vetor[100];
    
    fseek(arquivo, 0, SEEK_SET);
    fread(vetor, sizeof(Tarefa), totalRegistros, arquivo);
    
    for (int i = 0; i < totalRegistros - 1; i++) {
        for (int j = 0; j < totalRegistros - i - 1; j++) {
            if ((vetor[j].status > vetor[j + 1].status) ||
                (vetor[j].status == vetor[j + 1].status &&
                 vetor[j].id < vetor[j + 1].id)) {
                
                Tarefa temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
    
    printf("\n%-6s %-30s %-15s %-10s\n", "ID", "DESCRICAO", "RESP", "STATUS");
    printf("-------------------------------------------------------------\n");
    
    for (int i = 0; i < totalRegistros; i++) {
        if (vetor[i].ativo == 1) {
            printf("%-6d %-30s %-15s %-10s\n", 
                   vetor[i].id, 
                   vetor[i].descricao, 
                   vetor[i].responsavel, 
                   (vetor[i].status == 0) ? "PENDENTE" : "CONCLUIDO");
        }
    }

    printf("\nFim da lista.");
    pausa();
}

void editarTarefa(FILE* arquivo) {
    int idBusca;
    Tarefa t;
    int encontrado = 0;
    
    printf("\nInforme o ID da tarefa que deseja editar: ");
    scanf("%d", &idBusca);
    
    fseek(arquivo, 0, SEEK_SET);
    
    while (fread(&t, sizeof(Tarefa), 1, arquivo)) {
        if (t.id == idBusca && t.ativo == 1) {
            encontrado = 1;
            
            printf("\n--- Dados Atuais --- \n");
            printf("Descricao: %s | Resp: %s | Status: %s\n\n", 
                   t.descricao, t.responsavel, (t.status == 0) ? "PENDENTE" : "CONCLUIDO");
            
            printf("Nova Descricao: ");
            scanf(" %[^\n]", t.descricao);
            
            printf("Novo Responsavel: ");
            scanf(" %[^\n]", t.responsavel);
            
            do{
				printf("Status (0- Pendente, 1- Concluido): ");
				scanf("%d", &t.status);
				
				if(t.status != 0 && t.status != 1){
					printf("Status invalido! Digite 0 ou 1 para continuar.\n");
				}
				
			} while(t.status != 0 && t.status != 1);
            fseek(arquivo, -sizeof(Tarefa), SEEK_CUR);
            fwrite(&t, sizeof(Tarefa), 1, arquivo);
            fflush(arquivo);
            
            printf("\nTarefa atualizada com sucesso!\n");
            break;
        }
    }
    
    if (!encontrado) {
        printf("\nTarefa nao encontrada ou excluida.\n");
    }
    pausa();
}

void excluirTarefa(FILE* arquivo) {
    int idBusca;
    Tarefa t;
    int encontrado = 0;
    
    printf("\nInforme o ID da tarefa que deseja EXCLUIR: ");
    scanf("%d", &idBusca);
    
    fseek(arquivo, 0, SEEK_SET);
    
    while (fread(&t, sizeof(Tarefa), 1, arquivo)) {
        if (t.id == idBusca && t.ativo == 1) {
            encontrado = 1;
            t.ativo = 0; 

            fseek(arquivo, -sizeof(Tarefa), SEEK_CUR);
            fwrite(&t, sizeof(Tarefa), 1, arquivo);
            fflush(arquivo);
            
            printf("\nTarefa excluida com sucesso (Logicamente).\n");
            break;
        }
    }
    
    if (!encontrado) {
        printf("\nTarefa nao encontrada.\n");
    }
  }

int menu() {
    int opcao;
    printf("= MEU TO-DO LIST =\n");
    printf("1) Nova Tarefa\n");
    printf("2) Listar Tarefas\n");
    printf("3) Editar Tarefa\n");
    printf("4) Excluir Tarefa\n");
    printf("0) Sair\n");
    printf("Informe a opcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
    FILE* arquivo = abreArquivo("todolist.dat");
    if (!arquivo) return 1;
    
    int opcao;
    do {
        opcao = menu();
        switch(opcao) {
            case 1:
                novaTarefa(arquivo);
                break;
            case 2:
                listarTarefas(arquivo);
                break;
            case 3:
                editarTarefa(arquivo);
                break;
            case 4:
                excluirTarefa(arquivo);
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpcao invalida! Pressione ENTER...");
        }
        
    } while(opcao != 0);
    
    fclose(arquivo);
    return 0;
}
