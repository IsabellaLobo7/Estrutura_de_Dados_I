#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char selecao[50];
    int pontos;
    int saldo;
    int grupo;
} Selecao;

#define NUM_GRUPOS 4
#define MAX_POR_GRUPO 4
#define MAX_SELECOES 16

//função auxiliar para contar quantas selecoes estao em um grupo
int contSelecoesNoGrupo(Selecao copa[], int cont, char grupo){
    int qtd = 0;
    for(int i = 0; i < cont; i++){
        if(copa[i].grupo == grupo){
            qtd++;
        }
    }
    return qtd;
}

//menu do sistema
int interface(){
    int opcao;
    printf("\n=== COPA DO MUNDO ===\n");
    printf("1- Cadastrar Seleção\n");
    printf("2- Mostrar Classificação por grupos\n");
    printf("3- Informar Resultado\n");
    printf("4- Gerar Tabela de Jogos (Por Grupo) [NOVO]\n");
    printf("0- Sair\n");
    printf("Escolha uma opção: ");
    scanf(" %d", &opcao);
    return opcao;
}

Selecao cadastrarSelecao(Selecao copa[], int cont){
    Selecao nova;
    
    printf("Nome: \n");
    scanf(" %[^\n]s", nova.selecao);
    
    nova.pontos = 0;
    nova.saldo = 0;
    
    char grupoSorteado;
    
    do{
        grupoSorteado = 'A' + rand() % NUM_GRUPOS;
    }while (contSelecoesNoGrupo(copa, cont, grupoSorteado) >= MAX_POR_GRUPO);
    
    nova.grupo = grupoSorteado;
    printf("Seleção %s cadastrada com sucesso no grupo %c!\n", nova.selecao, nova.grupo);
    return nova;
}

void ordenacaoGrupo(Selecao copa[], int cont){
    for(int i = 0; i < cont-1; i++){
        // Correção aqui: alterado de i < cont-1-i para j < cont-1-i
        for (int j = 0; j < cont - 1 - i; j++){ 
            if (copa[j].grupo > copa[j + 1].grupo){
                Selecao troca = copa[j];
                copa[j] = copa[j+1];
                copa[j+1] = troca;
            }
        }
    }
}

void ordenacaoPontos(Selecao copa[], int cont){
    for(int i = 0; i < cont-1; i++){
        for (int j = 0; j < cont-1 - i; j++){
            if (copa[j].pontos < copa[j + 1].pontos){
                Selecao troca = copa[j];
                copa[j] = copa[j+1];
                copa[j+1] = troca;
            }
        }
    }
}

void ordenacaoSaldo(Selecao copa[], int cont){
    for(int i = 0; i < cont-1; i++){
        for (int j = 0; j < cont- 1 -i; j++){
            if (copa[j].saldo < copa[j + 1].saldo){
                Selecao troca = copa[j];
                copa[j] = copa[j+1];
                copa[j+1] = troca;
            }
        }
    }
}

void classificacao(Selecao copa[], int cont){
    ordenacaoSaldo(copa, cont);
    ordenacaoPontos(copa, cont);
    ordenacaoGrupo(copa, cont);
    
    printf("\n%-20s\t%s\t%s\t%s\n", "SELECAO", "PONTOS", "SALDO", "GRUPO");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < cont; i++){
        // Correção aqui: adicionado o argumento copa[i].pontos que faltava no seu print
        printf("%-20s\t%d\t%d\t%c\n", 
        copa[i].selecao,
        copa[i].pontos,
        copa[i].saldo,
        copa[i].grupo);
    }
}
    
int buscarSelecao(Selecao copa[], int cont, char time[]){
    for(int i = 0; i < cont; i++)
        if(strcmp (copa[i].selecao, time)==0){
            return i;
        }

    return -1;
}
    
void informarResultados(Selecao copa[], int cont){
    char time1[50];
    char time2[50];
    int placar1, placar2;
    
    printf("informe o nome do primeiro time: ");
    scanf(" %[^\n]s", time1);
    int localtime1 = buscarSelecao(copa, cont, time1);
    if(localtime1 == -1){
        printf("Time %s não cadastrado!\n", time1);
        return;
    }
    
    printf("Informe o nome do segundo time: ");
    scanf(" %[^\n]s", time2);    
    int localtime2 = buscarSelecao(copa, cont, time2);
    if(localtime2 == -1){
        printf("Time %s não cadastrado!\n", time2);
        return;
    }
    
    //validação de segurança: devem ser do mesmo grupo
    if (copa[localtime1].grupo != copa[localtime2].grupo){
        printf("ERRO: As seleções sao de grupos diferentes (%c VS %c)!\n", 
        copa[localtime1].grupo, copa[localtime2].grupo);
        return;
    }
    
    printf("Placar %s: ", time1);
    scanf(" %d", &placar1);
    printf("Placar %s: ", time2);
    scanf(" %d", &placar2);
    
    //atualiza os saldos do gols
    copa[localtime1].saldo += (placar1 - placar2);
    copa[localtime2].saldo += (placar2 - placar1);

    //calcula a pontuação com base no resultado da partida
    if (placar1 > placar2) {
        copa[localtime1].pontos += 3;
    } else if (placar2 > placar1) {
        copa[localtime2].pontos += 3;
    } else {
        copa[localtime1].pontos += 1;
        copa[localtime2].pontos += 1;
    }
    printf("Resultado computado com sucesso!\n");
}

// ADICIONAL: Função para o usuário escolher o grupo e o sistema gerar a tabela automaticamente
void gerarTabelaJogos(Selecao copa[], int cont) {
    char grupoEscolhido;
    
    printf("Digite o grupo para gerar a tabela de jogos (A, B, C ou D): ");
    scanf(" %c", &grupoEscolhido);
    
    // Forçar a letra a ser maiúscula caso digitem 'a', 'b', etc.
    if(grupoEscolhido >= 'a' && grupoEscolhido <= 'z') {
        grupoEscolhido = grupoEscolhido - 32; 
    }
    
    if(grupoEscolhido < 'A' || grupoEscolhido > 'D') {
        printf("Grupo inválido!\n");
        return;
    }

    printf("\n=== TABELA DE JOGOS - GRUPO %c ===\n", grupoEscolhido);
    
    int encontrouJogos = 0;
    int numJogo = 1;

    // Dois laços combinados cruzam todas as seleções do mesmo grupo sem repetir confrontos
    for(int i = 0; i < cont; i++) {
        if(copa[i].grupo == grupoEscolhido) {
            for(int j = i + 1; j < cont; j++) {
                if(copa[j].grupo == grupoEscolhido) {
                    printf("Jogo %d: %s x %s\n", numJogo, copa[i].selecao, copa[j].selecao);
                    numJogo++;
                    encontrouJogos = 1;
                }
            }
        }
    }

    if(!encontrouJogos) {
        printf("Nenhuma seleção cadastrada no grupo %c ainda.\n", grupoEscolhido);
    }
    printf("=================================\n");
}

int main(){
    srand(time(NULL)); //inicia gerador de num aleatorios
    Selecao copa[MAX_SELECOES];
    int cont = 0;
    int opcao;
    
    do{
        opcao = interface();
        switch (opcao){
            
            case 1: 
                if (cont < MAX_SELECOES){
                    copa[cont] = cadastrarSelecao(copa, cont);
                    cont++;
                }else{
                    printf("Limite maximo de 16 seleções atingido!\n");
                }
                break;
                
            case 2: 
                classificacao(copa, cont);
                break;
                
            case 3:
                informarResultados(copa, cont);
                break;

            case 4:
                // Chamada da nova funcionalidade solicitada
                gerarTabelaJogos(copa, cont);
                break;
            
            case 0: 
                printf("Saindo do sistema...\n");
                break;
        default:
            printf("Opção Invalida!\n");
            break;
        }
    }while (opcao != 0);
    
    return 0;
}
