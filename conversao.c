#include <stdio.h>
#include <stdlib.h>
int main (){
	
	char simbolo;
	int n, result, valores;
	
	printf("digite um simbolo numerico (0-9)" );
	scanf("%c", &simbolo);
	
	printf("digite um numero inteiro(n)" );
	scanf("%d", &n);
	
	result = valores * n;
	printf("o resultado correto é: %d\n", result);
	
	return 0;
}
