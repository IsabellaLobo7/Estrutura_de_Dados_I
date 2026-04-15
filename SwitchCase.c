#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int opcao;
	
	do {
	printf("\n----- MENU INTERATIVO -----\n" );
	printf ("\nDigite um valor (1 a 5) ou 0 para sair)" );
	scanf("%d", &opcao);
	
	switch(opcao) {
		case 1: 
		printf("um\n");
		break;
		
		case 2:
		printf("dois\n");
		break;
		
		case 3:
		printf("tres\n");
		break;
		
		case 4:
		printf("quatro\n");
		break;
		
		case 5:
		printf("cinco\n");
		break;
		
		case 0: 
		printf("encerrando o programa\n");
		break;
		
		default :
		printf("opção invalida! Tente novamente.\n");
		break;
		}
	} while (opcao != 0);
	
	return 0;

}
