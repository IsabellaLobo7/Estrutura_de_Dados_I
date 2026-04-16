#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int n, x;
	
	srand(time(NULL));
	
	printf("quantos numeros aleatórios voce quer geraer agora? ");
	scanf("%d", &n);
	
	printf("qual o valor máximo de intervalo?");
	scanf("%d", &x);
	
	printf("\nGerando %d numeros entre 0 e %d:\n", n, x);
	
	for (int i = 0; i < n; i++){
		int num_sort = rand() % (x + 1);
		printf("%d", num_sort);
	}
	printf("\n");
	
	return 0;
}
