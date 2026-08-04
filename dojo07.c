#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	
	char origem[100];
	char destino[100];
	int custo;
	int poltronas[50];
}Rota;

int interface(){
	
	int opc;
	
	printf("Informe a opcao desejada:\n");
	printf("1- Cadastrar Rotas\n");
	printf("2- Listar Rotas\n");
	printf("3- Buscar Rotas\n");
	printf("4- Escolher Poltrona\n");
	printf("Opção: ");
	scanf(" %d",&opc);
	
	return opc;
}

Rota cadastrarRotas(){
	
	Rota novo;
		
	printf("Informe o destino da rota:\n");
	scanf(" %[^\n]",novo.destino);
	
	printf("informe a origem da rota:\n");
	scanf(" %[^\n]", novo.origem);
	
	printf("Informe o custo da rota\n");
	scanf(" %d",&novo.custo);
	
	for (int i=0; i < 50; i++){
		novo.poltronas[i] = 0;
	}
	
	return novo;
}

void listarRotas(Rota rotas[],int contRotas){
	if(contRotas == 0) {
		printf("Nenhuma rota cadastrada.\n");
		return;
	}
	
	for(int i=0; i<contRotas; i++){
		
		printf("\n-----Rota %d -----\n", i + 1);
		printf("Origem: %s\n",rotas[i].origem);	
		printf("Destino: %s\n",rotas[i].destino);	
		printf("Custo: %d\n",rotas[i].custo);	
	}
}

void venderPassagem(Rota rotas[], int contRotas){
	char origemBusca[100];
	printf("Digite a origem da viagem: ");
	scanf(" %[^\n]", origemBusca);
	
int indiceAchado = -1;
for (int i=0; i< contRotas; i++){
	if (strcmp(origemBusca, rotas[i].origem) == 0){
		indiceAchado = i;
		break;
	}
}
	
if (indiceAchado == -1){
	printf("Rota não encontrada");
	return;
}

int numPoltrona;

	printf("Rota encontrada para %s! Escolha sua pçoltrona (1 a 50): ", rotas[indiceAchado].destino);
	scanf(" %d", &numPoltrona);
	
if (numPoltrona < 1 || numPoltrona > 50){
	printf("numero de poltrona invalida!\n");
	return;
}

int posicaoNoVetor = numPoltrona -1;

if (rotas[indiceAchado].poltronas[posicaoNoVetor] == 1){
	printf("ERRO: poltrona ja esta ocupada!\n");
	
}else{
	
	rotas[indiceAchado].poltronas[posicaoNoVetor]=1;
	printf("Passagem vendida com sucesso para poltrona %d!\n", numPoltrona);
	}
}

int main(){
	
	Rota rotas[100];
	int contRotas = 0;
	
	do{
		switch(interface()){
			
			case 1:rotas[contRotas++] = cadastrarRotas();
					break;
					
			case 2:listarRotas(rotas,contRotas);
					break;
					
			case 3: venderPassagem(rotas, contRotas);
					break;
					
			case 4: venderPassagem(rotas, contRotas);
					break;
			default:
					printf("Opção Invalida!\n");
					break;
		}
	}while(1);
	
	return 0;
}
