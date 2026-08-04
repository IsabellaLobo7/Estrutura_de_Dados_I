#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	int codigo;
	char descricao[100];
	float valor;
	int estoque;
}Produto;

//cadastrar um struct
//passagem de parametro por REFERENCIA
//retorno de função

void cadastrarProduto(Produto* p){
	printf("informe o codigo de barras: ");
	scanf("%d", &p->codigo);
	
	printf("informe a descrição: ");
	scanf(" %[^\n]", p->descricao);
	
	printf("informe o valor: ");
	scanf("%f", &p->valor);
	
	printf("informe o estoque disponivel: ");
	scanf("%d", &p->estoque);
	
	printf("Intem cadastrado com sucesso. Aperte ENTER para continuar...");
	}
	
	//imprimir produto
	void printProduto(Produto prod){
		printf("código: %d\n", prod.codigo);
		printf("descrição: %s\n", prod.descricao);
		printf("valor: %.2f\n", prod.valor);
		printf("estoque: %d\n", prod.estoque);
		
	}
	
	void venderProduto(Produto *p, int qt){
		if (p->estoque < qt) {
			printf("quantidade desse item não esta disponivel.\n");
			return;
	}
	p->estoque -= qt;
	printf("venda realizada com sucesso.\n");
}

//essa função ira simular a camada de visão!
//menu\interface
int interface(){
	int opcao;
	
	while(1){
		
		printf("========SISTEMA DE ESTOQUE ========\n");
		printf("1- Cadastrar Produto\n");
		printf("2- Listar Produtos\n");
		printf("3- Consultar um Produto\n");
		printf("4- Vender um produto\n");
		printf("5- Atualizar Estoque de Produto\n");
		printf("6- Fechamento de Caixa\n");
		printf("0- ENCERRAR SISTEMA\n");
		
		printf("Escolha uma opção:");
		scanf(" %d", &opcao);
		
		if(opcao < 0 || opcao > 5){
			printf("Opção Invalida!\n");
			continue;
		}
		
		return opcao;
	}
}

int main(){
	
	Produto p;
	
	do{
		switch(interface()){
			
			case 1: cadastrarProduto(&p);
			break;
			
			case 2: printProduto(p);
			break;
			
			case 3: printf("voce escolheu a opção 3\n");
			break;
			
			case 4: printf("voce escolheu a opção 4\n");
			break;
			
			case 5: printf("voce escolheu a opção 5\n");
			break;
			
			case 0: printf("ENCERRANDO O SISTEMA\n");
			return 0;
		}
		
		printf("\nAperte ENTER para continuar...");
		getchar();
		getchar();
		
	}while(1);
	return 0;
}
