#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x, y;
	float result;
	
	printf("digite x e y: ");
	scanf("%d %d", &x, &y);
	
	result = (float)x / y;
	
	printf("divisão: %.2f\n", result);
	printf("resto da divisão(mod): %d\n", x % y);
	
	return 0;
}
