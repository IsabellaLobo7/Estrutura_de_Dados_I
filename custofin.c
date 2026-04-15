#include <stdio.h>
#include <stdlib.h>
int main(){
	int x, y;
	float custo_fabrica, custo_imposto, custo_final;
	
	printf("digite o custo de produção: ");
	scanf("%f", &custo_fabrica);
	
	printf("digite a porcentagem de imposto(x):\n ");
	scanf("%d", &x);
	
	printf("digite a porcentagem do distribuidor(y):\n ");
	scanf("%d", &y);
	
	custo_imposto = custo_fabrica + (custo_fabrica * x/100.0);
	custo_final = custo_imposto + (custo_imposto * y/100.0);
	
	printf("o custo final do produto é: R$ %.2f\n", custo_final);
	
	return 0;
	
}
