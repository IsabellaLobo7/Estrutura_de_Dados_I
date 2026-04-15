#include <stdio.h>
#include <stdlib.h>
int main (){
	char letra;
	
	printf("digite um caractere:" );
	scanf("%c", &letra);
	
	printf("exibindo com %%c: %c\n", letra );
	printf("exibindo com %%d: %d\n", letra );
	
	return 0;
}
