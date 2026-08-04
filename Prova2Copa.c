#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char selecao[50];
    int pontos;
    int saldo;
    char grupo;
} Selecao;

#define MAX_SELECOES 40 // Define um limite máximo seguro para armazenar múltiplos grupos (ex: 10 grupos de 4)
#define TIMES_POR_GRUPO 4

// Função auxiliar para buscar se uma seleção já existe no sistema (em qualquer grupo)
int buscarSelecaoGeral(Selecao copa[], int cont, char time[]) {
    for (int i = 0; i < cont; i++) {
        if (strcasecmp(copa[i].selecao, time) == 0) {
            return i; // Retorna o índice se já estiver cadastrada
        }
    }
    return -1; // Não encontrada
}

// Função auxiliar para verificar se um grupo já existe
int grupoExiste(Selecao copa[], int cont, char grupo) {
    for (int i = 0; i < cont; i++) {
        if (copa[i].grupo == grupo) {
            return 1; // Grupo já possui seleções cadastradas
        }
    }
    return 0;
}

// Menu Inicial da Aplicação solicitado na prova
int interface() {
    int opcao;
    printf("\n= COPA DO MUNDO =\n");
    printf("1) Criar Grupo\n");
    printf("2) Informar Resultados de um Grupo\n");
    printf("3) Imprimir Classificacao Geral\n");
    printf("0) Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// Requisito 1: Criar Grupo e cadastrar as 4 seleções com as devidas validações
int criarGrupo(Selecao copa[], int cont) {
    char grupoEscolhido;
    printf("\nInforme o nome do grupo (p.ex. A, B, C...): ");
    scanf(" %c", &grupoEscolhido);
    
    // Converter para maiúscula caso digitem em minúscula
    if (grupoEscolhido >= 'a' && grupoEscolhido <= 'z') {
        grupoEscolhido -= 32;
    }

    // Validação: Um grupo não pode ser recriado se já existir
    if (grupoExiste(copa, cont, grupoEscolhido)) {
        printf("ERRO: O grupo %c ja esta cadastrado!\n", grupoEscolhido);
        return cont;
    }

    printf("Cadastre os 4 times do Grupo %c:\n", grupoEscolhido);
    for (int i = 0; i < TIMES_POR_GRUPO; i++) {
        char nomeTime[50];
        while (1) {
            printf("Selecao %d: ", i + 1);
            scanf(" %[^\n]s", nomeTime);

            // Restrição: Não pode conter seleções repetidas nem em outros grupos
            if (buscarSelecaoGeral(copa, cont, nomeTime) != -1) {
                printf("ERRO: A selecao '%s' ja esta cadastrada no sistema! Digite outra.\n", nomeTime);
            } else {
                // Cadastro válido
                strcpy(copa[cont].selecao, nomeTime);
                copa[cont].pontos = 0;
                copa[cont].saldo = 0;
                copa[cont].grupo = grupoEscolhido;
                cont++;
                break;
            }
        }
    }
    printf("Grupo %c criado com sucesso!\n", grupoEscolhido);
    return cont;
}

// Requisito 2: Informar resultados dos 06 jogos usando laços de repetição e impedindo placar negativo
void informarResultadosGrupo(Selecao copa[], int cont) {
    char grupoEscolhido;
    printf("\nInforme o nome de um grupo existente: ");
    scanf(" %c", &grupoEscolhido);

    if (grupoEscolhido >= 'a' && grupoEscolhido <= 'z') {
        grupoEscolhido -= 32;
    }

    if (!grupoExiste(copa, cont, grupoEscolhido)) {
        printf("ERRO: Grupo %c nao existe ou nao possui selecoes cadastradas!\n", grupoEscolhido);
        return;
    }

    // Vetor de ponteiros ou índices temporários para mapear os 4 times do grupo informado
    int indicesGrupo[TIMES_POR_GRUPO];
    int k = 0;
    for (int i = 0; i < cont; i++) {
        if (copa[i].grupo == grupoEscolhido) {
            indicesGrupo[k] = i;
            k++;
        }
    }

    printf("\n--- Informar Resultados dos 06 Jogos do Grupo %c ---\n", grupoEscolhido);
    int numJogo = 1;

    // Laços de repetição para gerar e computar os 6 confrontos automaticamente
    for (int i = 0; i < TIMES_POR_GRUPO; i++) {
        for (int j = i + 1; j < TIMES_POR_GRUPO; j++) {
            int idx1 = indicesGrupo[i];
            int idx2 = indicesGrupo[j];
            int placar1, placar2;

            printf("\nJogo %d: %s x %s\n", numJogo++, copa[idx1].selecao, copa[idx2].selecao);
            
            // Restrição: Não permitir placar com valor negativo
            do {
                printf("Placar %s: ", copa[idx1].selecao);
                scanf("%d", &placar1);
                if (placar1 < 0) printf("ERRO: O placar nao pode ser negativo!\n");
            } while (placar1 < 0);

            do {
                printf("Placar %s: ", copa[idx2].selecao);
                scanf("%d", &placar2);
                if (placar2 < 0) printf("ERRO: O placar nao pode ser negativo!\n");
            } while (placar2 < 0);

            // Computar saldos de gols
            copa[idx1].saldo += (placar1 - placar2);
            copa[idx2].saldo += (placar2 - placar1);

            // Computar pontuação
            if (placar1 > placar2) {
                copa[idx1].pontos += 3;
            } else if (placar2 > placar1) {
                copa[idx2].pontos += 3;
            } else {
                copa[idx1].pontos += 1;
                copa[idx2].pontos += 1;
            }
        }
    }
    printf("\nTodos os 6 resultados do Grupo %c foram computados!\n", grupoEscolhido);
}

// Requisito 3: Ordenação combinada por (i) Nome do grupo crescente, (ii) Pontos decrescente e (iii) Saldo decrescente
void ordenarClassificacaoGeral(Selecao copa[], int cont) {
    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - 1 - i; j++) {
            int trocar = 0;

            // Critério (i): Ordem alfabética do grupo (A, B, C...)
            if (copa[j].grupo > copa[j + 1].grupo) {
                trocar = 1;
            } 
            // Se forem do mesmo grupo, aplica o critério (ii): Maior soma de pontos
            else if (copa[j].grupo == copa[j + 1].grupo) {
                if (copa[j].pontos < copa[j + 1].pontos) {
                    trocar = 1;
                } 
                // Se empatarem em pontos, aplica o critério (iii): Maior saldo de gols
                else if (copa[j].pontos == copa[j + 1].pontos) {
                    if (copa[j].saldo < copa[j + 1].saldo) {
                        trocar = 1;
                    }
                }
            }

            if (trocar) {
                Selecao aux = copa[j];
                copa[j] = copa[j + 1];
                copa[j + 1] = aux;
            }
        }
    }
}

// Imprime o relatório final formatado da classificação
void imprimirClassificacao(Selecao copa[], int cont) {
    if (cont == 0) {
        printf("\nNenhuma selecao cadastrada no sistema ainda.\n");
        return;
    }

    ordenarClassificacaoGeral(copa, cont);

    printf("\n==================== CLASSIFICACAO GERAL ====================\n");
    printf("%-5s %-25s %-8s %-5s\n", "GRUPO", "SELECAO", "PONTOS", "SALDO");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < cont; i++) {
        printf("  %c   %-25s %-8d %-5d\n", 
               copa[i].grupo, 
               copa[i].selecao, 
               copa[i].pontos, 
               copa[i].saldo);
    }
    printf("=============================================================\n");
}

int main() {
    Selecao copa[MAX_SELECOES];
    int cont = 0;
    int opcao;

    do {
        opcao = interface();
        switch (opcao) {
            case 1:
                if (cont + TIMES_POR_GRUPO <= MAX_SELECOES) {
                    cont = criarGrupo(copa, cont);
                } else {
                    printf("Limite maximo de selecoes do sistema atingido!\n");
                }
                break;
            case 2:
                informarResultadosGrupo(copa, cont);
                break;
            case 3:
                imprimirClassificacao(copa, cont);
                break;
            case 0:
                printf("Saindo da aplicacao...\n");
                break;
            default:
                printf("Opcao Invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
