#include <stdio.h>

int main(){
	int n;
	
	printf("digite o valor inicial: ");
	scanf("%d", &n);
	
	for (int i = n; i>= 1; i--){
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		if (i == n){
			printf("(%d)", n);
		}
		printf("\n");
	}
	return 0;
}
