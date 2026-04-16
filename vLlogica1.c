#include <stdio.h>

int main(){
	int n, i;
	int e_primo = 1;
	
	printf("digite um numero inteiro positivo: ");
	scanf("%d", &n);
	
	if (n <= 1){
		e_primo = 0;
		
	}else{
		for (i = 2; i < n; i++) {
			if (n % i== 0) {
				e_primo = 0;
				break;
			}
		}
	}
	
	if (e_primo == 1 ){
		printf("o numero %d é primo.\n", n);
	} else{
			printf("o numero %d nao é primo.\n", n);
		}
	return 0;
}
