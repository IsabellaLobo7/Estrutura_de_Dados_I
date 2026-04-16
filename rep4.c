#include <stdio.h>
#include <limits.h>

int main(){
	
	int n, valor, soma = 0, contV = 0;
	int maior, menor;
	
	printf("quantos numeros voce deseja digitar? ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		printf("digite o %d° numero: ", i + 1);
		scanf("%d", &valor);
		if (valor > 0){
			if (contV == 0){
				maior = valor;
				menor = valor;
			} else{
				if (valor > maior) maior = valor;
				if (valor < menor) menor = valor;
			}
			
			soma += valor;
			contV++;
		}
	}
	
	if (contV > 0){
		float media = (float)soma / contV;
		
		printf("\n--- RESULTADOS ---");
		printf("\nMaior valor: %d", maior);
		printf("\nMenor valor: %d", menor);
		printf("\nSoma: %d", soma);
		printf("\nMedia simples: %.2f\n", media);
		
	} else{
	printf("\nNenhum valor positivo valido foi inserido.\n");
}
	return 0;
}
