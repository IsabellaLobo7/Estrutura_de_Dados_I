#include <stdio.h>
#include <stdlib.h>
int main (){
	char nome[50];
	float litro, valor, combustivel;
	
	printf("ola qual o seu nome? ");
	fgets(nome, 50, stdin);
	
	printf("qual o preço do litro de combustivel? ");
	scanf("%f", &litro);
	
	printf("qual valor de combustivel o motorista deseja abastecer?" );
	scanf("%f", &valor);
	
	combustivel = valor/litro;
	printf("a quantidade de combustivel que sera dispensada é de: %.3f", combustivel);
	
	return 0;
}
