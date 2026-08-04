#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int potencia(int x, int n){
	int resultado = 1;
	int i;
	for(i=0; i<n; i++){
		resultado *= x;
	}
	return resultado;
}

	int main(){
		int x;
		int n;
		
	printf("Digite a base (x): ");
		scanf("%d", &x);
	
	printf("digite o expoente (N)");
	scanf("%d", &n);
	
	printf("%d ^ %d = %d\n", x, n, potencia(x, n));
	
	return 0;
}

