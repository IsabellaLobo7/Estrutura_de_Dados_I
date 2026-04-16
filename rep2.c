#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int n;
	printf("digite um valor inteiro: ");
	scanf("%d", &n);
	
	printf("\nValores pares de 0 ate %d(crescente):\n", n);
	for (int i = 0; i <= n; i++){
		if (i % 2 == 0) {
			printf("%d", i);
		}
	}
	
	printf("\n\nValores impares de %d ate 0 (decrescente):\n", n);
	for (int i = n; i >= 0; i--){
		if  (i % 2 != 0){
			printf("%d", i);
		}
	}
	
	printf("\n");
	return 0;
}
