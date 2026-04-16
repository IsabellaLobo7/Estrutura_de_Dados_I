#include <stdio.h>
int main(){
	
	int n, i, j, primo_ant = 0, primo_prox = 0;
	int e_primo;
	
	printf("digite um valor interio: ");
	scanf("%d", &n);
	
	for (i = n - 1; i >= 2; i--){
		e_primo = 1;
		for (j = 2; j < i; j++){
			if (i %j == 0){
				e_primo = 0;
				break;
			}
		}
		if (e_primo == 1){
			primo_ant = i;
			break;
			
		}
	}
	
	for (i = n + 1; ;i++) {
		e_primo = 1;
			for (j = 2; j < i; j++){
				if (i % j ==0) {
					e_primo = 0;
					break;
				}
			}
			
			if (e_primo == 1) {
				primo_prox = i;
				break;
		}
		
		if (primo_ant != 0){
			printf("maior primo menor que %d: %d\n", n, primo_ant);
		} else{
			printf("nao existe primo menor que %d no conjunto dos naturais.\n", n);
		}
		printf("menor primo maior que %d: %d\n", n, primo_prox);
	
}
		
		return 0;
}
