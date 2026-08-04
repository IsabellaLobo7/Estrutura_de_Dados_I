#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int soma(int a, int b){
	return a + b;
}

int subtracao(int a, int b){
	return a - b;
}

int mult(int a, int b){
	return a * b;
}

int divisao(int a, int b){
	
	if (b==0){
		printf("Erro! Divisao por zero.*");
		return 0;
	}
	
	return a/b;
}
int potencia(int x, int n){
	int resultado = 1;
	
	for (int i=0; i<n; i++){
		resultado *= x;
	}
		return resultado;
}

int interface(){
	
	int opcao;
	
	printf("==========CALCULADORA=========\n");
	printf("1- SOMA\n");
	printf("2- SUBTRAÇÃO\n");
	printf("3- MULTIPLICAÇÃO\n");
	printf("4- DIVISÃO\n");
	printf("5- POTENCIA\n");
	printf("0- SAIR\n");
	
	scanf("%d", &opcao);
	
	return opcao;
}

int main(){
	int opcao;
	int a,b;
	
	do{
		opcao = interface();
		if (opcao >= 1 && opcao <= 4){
			
			printf("Digite dois numeros: ");
			scanf ("%d %d", &a, &b);
		}
		switch (opcao){
			
			case 1:
				printf("Resultado: %d\n", soma(a,b));
				break;
			
			case 2:
				printf("Resultado: %d\n", subtracao(a,b));
				break;
			
			case 3:
				printf("Resultado: %d\n", mult(a,b));
				break;
			
			case 4:
				if (b!=0)
					printf("Resultado: %d\n", divisao(a,b));
				break;
			
			case 5:
				printf("Base e expoente inteiros: ");
				scanf("%d %d", &a, &b);
			
				printf("Resultado: %d\n", potencia(a,b));
				break;
			
			case 0:
				printf("ENCERRANDO...\n");
				break;
			
			default:
					printf("OPÇÃO INVALIDA.\n");
		}
			
		}while(opcao != 0);
	return 0;
}
