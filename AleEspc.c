#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int n, x, y, menor, maior;
	
	srand(time(NULL));
	
	printf("quantos numeros aleatorios? ");
	scanf("%d", &n);
	
	printf("informe o valor de x: ");
	scanf("%d", &x);
	
	printf("informe o valor de y: ");
	scanf("%d", &y);
	
	if (x < y) {
		menor = x;
		maior = y;
		
	} else{
		
		menor = y;
		maior = x;
	}
	
	printf("\nGerando %d numeros entre %d e %d\n: ", n, menor, maior);
	for (int i = 0; i < n; i++){
		int num = (rand() % (maior - menor + 1)) + menor;
		printf("%d", num);
	}
	
	printf("\n");
	return 0;
}
