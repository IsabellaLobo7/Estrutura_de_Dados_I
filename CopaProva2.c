#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRUPOS 10
#define TIMES_GRUPOS 4

typedef struct{
	char nome[50];
	int pontos;
	int saldo;
} Selecao;

typedef struct{
	char grupo;
	Selecao times[TIMES_GRUPOS];
} Grupo;

int existeSelecao(Grupo grupos[], int qtdGrupos, char nome[]){
	
	for(int i = 0; i < qtdGrupos; i++){
		for(int j = 0; j < TIMES_GRUPOS; j++){
			
if(strcmp(grupos[i].times[j].nome, nome)== 0){
	return 1;
				}
			}
		}
	}
	return 0;
}

void criarGrupo(Grupo grupos[], int *qtdGrupos){
	if(*qtdGrupos >= MAX_GRUPOS){
		printf("Limitre de grupos atingido!\n");
		return;
	}
	
	Grupo g;
	
	printf("Nome do Grupo: ");
	scanf(" %[^\n]", g.times[i].nome);
	
if (existeSelecao(grupos, *qtdGrupos,g.times[i].nome)){
	
	printf("Selecao ja cadastrada!\n");
	}

}

while(existeSelecao(grupos, *qtdGrupo,g.times[i].nome));

		g.times[i].pontos = 0;
		g.times[i].saldo = 0;
	}
	
	grupos[*qtdGrupos] = g;
	(*qtdGrupos)++;
	
	printf("Grupo criado com sucesso!\n");
}

void informarResultados(Grupo grupos[], int qtdGrupos){
	
	char letra;
	int indice = -1;
	
	printf("Informe o grupo: ");
	scanf( "%c", &letra);
	
	for (int i = 0; i < qtdGrupos; i++){
		if(grupos[i].grupo == letra){
			indice = i;
			break;
		}
	}
	
	if(indice == -1){
		printf("Grupo nao encontrado!\n");
		return;
	}
	
	Grupo *g = &grupos[indice];
	
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 4; j++){
			
			int gol1, gol2;
			
			printf("\n%s x %s\n",
					g -> times[i].nome,
					g -> times[j].nome);
					
				do{
					printf("Gols %s: ", g->times.nome);
					scanf( "%d", &gol1);
				}while(gol1 < 0);
				
				do{
					printf("Gols %s: ", g->times[j].nome);
					scanf( "%d", &gol2);
				}while(gol2 < 0);
				
				g->times[i].saldo += (gol1-gol2);
				
				g->times[j].saldo += (gol2 - gol1);
				
				if(gol1 > gol2){
					g -> times[i].pontos += 3;
				}
				else if (gol2 > gol1){
					g-> tmes[j].pontos += 3;
				}
				else{
					g -> times[i].pontos ++;
					g -> times[j].pontos++;
				}
			}
		}
		
		printf("\nResultados registrados!\n");
	}
	
	void ordenarGrupos(Grupo grupos[], int qtdGrupos){
		
		for (int i =0; i < qtdGrupos -1; i+=){
			for (int j = i + 1; j < qtdGrupos; j++){
				
				if (grupos[i].grupo > grupos[j].grupo){
					
					Grupo aux = grupos[i];
					grupos[i] = grupos[j];
					grupos[j] = aux;
				}
			}
		}
	}
	
	void ordenarPontos (Selecao times[]){
		
		for (int i = 0; i < 3; i++){
			for (int j = i + 1; j < 4; j++){
				
				if (times[j].pontos > times[i].pontos){
					
					Selecao aux = grupos[i];
					grupos[i] = grupos[j];
					grupos[j] = aux;
				}
			}
		}
	}
	
	

