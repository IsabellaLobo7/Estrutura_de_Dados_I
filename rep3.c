#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int v1, v2, menor, maior;
	int entV = 0;
	
	do{
		printf("digite dois valores inteiros (um par e um  impar): ");
		scanf("%d %d", &v1, &v2);
		if ((v1 % 2 == 0 && v2 % 2 != 0) || (v1 % 2 != 0 && v2 % 2 == 0)){
			entV = 1;
		} else {
			printf("erro! voce deve digitar obrigatoriamente um par e um impar.\n");
		}
	}while (!entV);
	if (v1 < v2); {
		menor = v2;
		maior = v1;
	}
	printf("\nNumeros no intervalo entre %d e %d:\n", menor, maior);
		for(int i = menor; i <= maior; i++){
			printf("%d", i);
		}
		 
		 printf("\n");
		 return 0;
}
