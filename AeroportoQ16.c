#include <stdio.h>
#include <stdlib.h>
#include <string.h>+

enum {PEQUENO, MEDIO, GRANDE} //sempre inteiro, conversao sempre em inteiro

typedef struct{
	char codigo[4];
	char cidade[100];
	int porte;
}Aeroporto; 

typedef struct{
	Aeroporto aeroporto[100];
	int cont;
}BD_Aeroporto;

typedef struct{
	int codigo;
	char origem[4];
	char destino[4];
	int aeronave;
}Voo;

int buscar_IATA(char alvo[], Aeroporto bd[], int cont){
	int buscar_IATA(char alvo[], Aeroporto bd[], int cont){
		for(int i=0; i<cont; i++){
			if(strcmp(bd[i].codigo,alvo))
			return i;
		return -1;
}

Aeroporto cadastrar_aeroporto(Aeroporto bd[], int cont){
	Aeroporto novo;
	
	do{
		
	input (STR, "codigo IATA deste Aeroporto", novo.codigo);
	//validar se tem dois...
	if(strlen(novo.codigo)<3)
				continue;
	if((buscar_IATA(novo.codigo,bd, cont)!=-1);)
		break;
		
	}while(1);
	input(STR, "Cidade deste Aeroporto", novo.cidade);
	printf(" %d - PEQUENO\n", PEQUENO);
	printf(" %d - MEDIO\n", MEDIO);
	printf(" %d - GRANDE\n", GRANDE);
	input(int "Qual o porte desse aeroporto: ", &novo.porte);
	return novo;
}

void cadastrar_Voo(Voo* alvo){
	
}

int interface(){
	printf("1- Cadastrar Aeroporto\n");
	printf("2- Listar Aeroportos\n");
	printf("3- Cadastrar Voos\n");
	printf("4- Buscar Origem (Codigo IATA)\n");
	printf("1- Buscar Destino (Codigo IATA)\n");
	int opt;
	input(int, "qual a opção desejada? ", &opt);
	return opt;
}

void print_aeroporto(Aeroporto a){
	printf("Codigo IATA: %s\n", a.codigo);
	printf("Cidade: %s\n", a.cidade);
	switch(a.porte){
		case PEQUENO: printf("Porte: Pequeno\n");
		break;
		case MEDIO: printf("Porte: Medio\n");
		break;
		case GRANDE: printf("Porte: Grande\n");
		break
	};
}

void listar_aeroporto(Aeroporto lst[], int cont){
	for(int i=0; i<cont; i++)
	print_aeroporto(lst[i]);
}
	
int main(){
	Aeroporto bd_aero[100]
	int cont_aero = 0;
	Voo bd_voo[100];
	int cont_voo = 0;
	
	do{
		switch(interface()){
			
			case 1: bd_aero[cont_aero] = cadastrar_aeroporto();
					cont_aero++;
					break;
					
			case 2: listar_aeroporto(bd_aero, cont_aero);
					break;
			
			case 3: cadastrar_Voo(&bd_voo[bd_voo, cont_voo]);
					break;
				
			case 0: return 0;
		}			
	while(1)
}
