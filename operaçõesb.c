#include <stdio.h>
int main  () {
	int num1, num2;
	int soma, sub, mult, quadrado;
	float div; 
	printf("digite o primeiro numero inteiro: ");
	scanf("%d", &num1);
	printf("digite o segundo numero inteiro: ");
	scanf("%d", &num2);
	
	soma = num1 + num2;
	sub = num1 - num2;
	mult = num1 * num2; 
	
		printf("\n--- RESULTADO ---\n");
		printf("soma: %d\n", soma);
		printf("subtracao: %d\n", sub);
		printf("multiplicacao: %d\n", mult);
		
	if (num2 != 0) {
		div = (float)num1 / num2;
		printf("divisao: %2f\n", div);
	} else {
		printf("divisao: nao e possivel dividir por zero!\n");
	}
	
		printf("quadrado da subtracao: %d\n", quadrado);
		
		return 0;
	}
