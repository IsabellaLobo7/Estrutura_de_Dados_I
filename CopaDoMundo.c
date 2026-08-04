#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//nome da seleção
//os pontos da seleção
//saldo de gols
//e os ghrupos
//ordenar nivel inferiror ate o superiror
//ordenar por pontos decrescentes

#define MAX_SELECOES 16

typedef struct{
	char nome[40];
	char grupo;
	int pontos;
	int saldo_gols;
} Selecao; 

void cadastrarESortear(Selecao vetor[], int *total);
void exibirTodosOsGrupos(Selecao vetor[], int total);
void ordenarPorPontos(Selecao vetor[], int tamanho);

int main(){
	
	srand(time(NULL));
	Selecao torneio[MAX_SELECOES];
	int total_cadastrado = 0;
	int opcao;
	
	do {
		printf("\n ===================\n");
		printf("  SISTEMA COPA DO MUNDO   \n");
		printf("====================\n");
		printf("1- Cadastrar e Sortear Seleção (%d/%d/)\n", total_cadastrado, MAX_SELECOES);
		printf("2- Mostrar Classificação por Grupos\n");
		printf("0- Sair\n");
		printf("Escolha uma Opção: ");
		
		if (scanf ("%d", &opcao) != 1){
			opcao = -1;
		}
		
		getchar();
		
		switch(opcao){
			case 1:
				cadastrarESortear(torneio, &total_cadastrado);
				break;
			case 2: 
				exibirTodosOsGrupos(torneio, total_cadastrado);
				break;
			case 0: 
				printf("Saindo do sistema...\n");
				break;
			default:
				printf("Opção invalida!\n");
			}
		}while(opcao !=0);
		
		return 0;
	}
	
	void cadastrarESortear(Selecao vetor[], int *total){
		if (*total >= MAX_SELECOES) {
			printf("\n[ERRO] O torneio ja esta lotado com 16 seleções!\n");
			return ;
		}
		
		Selecao nova;
		printf("\nDigite o nome da seleção: \n");
		fgets(nova.nome, 40, stdin);
		nova.nome[strcspn(nova.nome, "\n")] = 0;
		
		for(int i = 0; nova.nome[i]; i++){
			nova.nome[i] = toupper(nova.nome[i]);
		}
		
		nova.pontos = 0;
		nova.saldo_gols = 0;
		
		int grupo_valido = 0;
		char grupo_sorteado;
		
		while (!grupo_valido){
			int r = rand() % 4;
			grupo_sorteado = 'a' + r;
			
			
		int cont_grupo = 0;
		for (int i = 0; i < *total; i++){
			if (vetor[i].grupo == grupo_sorteado){
				cont_grupo++;
			}
		}
		
		nova.grupo = grupo_sorteado;
		
		vetor[*total] = nova;
		(*total)++;
		
		printf("\n[SUCESSO] %s cadastrada com sucesso e sorteada para o grupo %c\n", nova.nome, nova.grupo);
	}
	
void exibirTodosOsGrupos(Selecao vetor[], int total){
	if (total == 0){
		printf("\nNenhuma seleção cadastrada ainda.\n");
		return;
	}
	
	char letras_grupos[4] = {'A', 'B', 'C', 'D'};
	
	for(int g = 0; g < 4; g++){
		char grupo_atual = letras_grupos[g];
		
		Selecao temp_grupo[4];
		int qtd_grupo = 0;
		
		for(int i = 0; i < total; i++){
			if (vetor i = 0; i < total; i++){
				temp_grupo[qtd_grupo] = vetor[i];
				qtd_grupo++;
			}
		}
		8
	printf("\n=== GRUPO %c===\n", grupo_atual);
	if (qtd_grupo == 0){
		printf("Nenhuma seleção neste grupo ainda.\n");
		continue;
	}
	
	ordenarPorPontos(temp_grupo, qtd_grupo);
	
	printf("%-4s | %-15s | %-6s | %-5s\n", "seleção", "pontos", "saldo");
	printf("-------------------------------\n");
	for(int i = 0; i < qtd_grupo; i++){
		printf("%d | %-15s | %-6d | %-5d\n";
			i + 1, temp_grupo[i].nome, temp_grupo[i].pontos, temp_grupo[i].saldo_gols);
		}
	}
}

void ordenarPorPontos(Selecao vetor[], int tamanho){
	Selecao temp;
	for(int i = 0; i < tamanho - 1; i++){
		for(int j = 0; j < tamanho - i - 1; j++){
			if (vetor[j].pontos < vetor[j + 1].pontos){
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
			
			else if (vetor[j].pontos == vetor[j + 1].pontos){
				if (vetor[j].saldo_gols < vetor[j + 1]. saldo_gols){
					temp = vetor[j];
					vetor[j] = vetor[j + 1];
					vetor[j + 1] = temp;
				}
			}
		}
	}
}
