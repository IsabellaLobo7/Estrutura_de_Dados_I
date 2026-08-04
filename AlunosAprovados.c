#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int matricula;
	char nome[50];
	float nota;
}Aluno;
Aluno aluno[5];

int main(){
	
	for(int i=0; i<5; i++){
		printf("Digite o numero de matricula do aluno: \n");
		scanf("%d", &aluno[i].matricula);
		printf("Digite o nome do aluno: \n");
		scanf("%s", aluno[i].nome);
		printf("Digite a nota do semestre do aluno: \n");
		scanf("%f", &aluno[i].nota);
	}
	for(int i=0; i<5; i++){
		if(aluno[i].nota>60){
			printf("\nAluno %d APROVADOS:", i+1);
			printf("Numero de matricula do aluno: %d\n", aluno[i].matricula);
			printf("Nome do aluno: %s\n", aluno[i].nome);
			printf("Nota do aluno: %2.f\n", aluno[i].nota);
			}
			
			else{
				printf("\nAluno %d REPROVADOS: ", i+1);
				printf("Nome do aluno: %s\n", aluno[i].nome);
				printf("Nota do aluno: %.2f\n", aluno[i].nota);
			}
		}
	}
