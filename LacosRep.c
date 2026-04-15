#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, valor, maior, menor, soma = 0;
	float media;
	
	for (i = 1; i <= 10; i++){
		printf("digite o %do valor:", i);
		scanf("%d", &valor);
		
		soma += valor;
		
		if (i == 1){
			maior = valor;
			menor = valor;
			
		} else {
			if (valor > maior) maior = valor;
			if (valor < menor) menor = valor;
		}
	}
	
	media = soma / 10.0; 
	
	printf("\nMaior valor: %d", maior);
	printf("\nMenor valor: %d", menor);
	printf("\nMedia: %.2f\n", media);
	
	return 0;
}
