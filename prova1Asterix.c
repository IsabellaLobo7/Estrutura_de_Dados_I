#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main (){
	
	srand(time(NULL));
	
	int n, i, j, aux;
	float soma=0, media;
	int maior, menor; 
	
	
	printf("informe o numero de jogadores:");
	scanf("%d", &n);
	
	int v[n];
	
	for (i=0; i<n; i++){
		printf("digite o valor %d:", i + 1);
		scanf("%d", &v[i]);
		soma += v[i];
		
		if (i == 0){
			maior = v[i];
			menor = v[i];
		}else {
		if (v[i] > maior) maior = v[i];
		if (v[i] < menor) menor = v[i];
		}
		
	}
	
	for (i=0; i<n; i++){
		for (j=i + 1; j<n; j++){
			if (v[i] < v[j]){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
	}
	
	media = soma / n;
	
	system("clear");
	printf("--- RESULTADO DA CORRIDA---\n\n");
	
	for (i=0; i<n; i++){
		printf("posição %02d [Pontos: %02d]:", i+1, v[i]);
		for (j=0; j<v[i]; j++){
			printf("*");
			
	}
		printf("\n");
	
}
	printf("\nMaior: %d", maior);
	printf("\nMenor: %d", menor);
	printf("\nMedia: %.2f\n", media);
	
	return 0;
}
