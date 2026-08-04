#include <stdio.h>
#include <string.h>

#define MAX_PROCESSOS 10
#define MAX_RECURSOS 10

typedef struct {
    char nome[10];
    int alocacao[MAX_RECURSOS];
    int maximo[MAX_RECURSOS];
    int necessidade[MAX_RECURSOS];
    int finalizado;
} Processo;

typedef struct {
    int n_processos;
    int n_recursos;
    Processo processos[MAX_PROCESSOS];
    int disponiveis[MAX_RECURSOS];
    int sequencia[MAX_PROCESSOS]; 
    int tam_sequencia;
} Sistema;


void calcular_necessidades(Sistema *s) {
    int i, j;
    for (i = 0; i < s->n_processos; i++) {
        for (j = 0; j < s->n_recursos; j++) {
            s->processos[i].necessidade[j] =
                s->processos[i].maximo[j] - s->processos[i].alocacao[j];
        }
    }
}

int pode_atender(Sistema *s, int i, int disponiveis_temp[]) {
    int j;
    for (j = 0; j < s->n_recursos; j++) {
        if (s->processos[i].necessidade[j] > disponiveis_temp[j]) {
            return 0;
        }
    }
    return 1;
}

int verificar_estado_seguro(Sistema *s) {
    int disponiveis_temp[MAX_RECURSOS];
    int finalizado_temp[MAX_PROCESSOS];
    int i, j, encontrou, passos;

    
    for (j = 0; j < s->n_recursos; j++)
        disponiveis_temp[j] = s->disponiveis[j];

    for (i = 0; i < s->n_processos; i++)
        finalizado_temp[i] = 0;

    s->tam_sequencia = 0;

    
    for (passos = 0; passos < s->n_processos; passos++) {
        encontrou = 0;

        for (i = 0; i < s->n_processos; i++) {
            if (finalizado_temp[i]) continue;

            if (pode_atender(s, i, disponiveis_temp)) {
                
                for (j = 0; j < s->n_recursos; j++)
                    disponiveis_temp[j] += s->processos[i].alocacao[j];

                finalizado_temp[i] = 1;
                s->sequencia[s->tam_sequencia++] = i;
                encontrou = 1;
                break; 
            }
        }

        if (!encontrou) break; 
    }

    return (s->tam_sequencia == s->n_processos);
}

void imprimir_tabela(Sistema *s) {
    int i, j;

    printf("\n============================================================\n");
    printf("          ESTADO ATUAL DO SISTEMA\n");
    printf("============================================================\n");

    printf("%-10s", "Processo");
    for (j = 0; j < s->n_recursos; j++) printf("  R%d(Aloc)", j);
    for (j = 0; j < s->n_recursos; j++) printf("  R%d(Max) ", j);
    for (j = 0; j < s->n_recursos; j++) printf("  R%d(Nec) ", j);
    printf("\n");

    printf("%-10s", "----------");
    for (j = 0; j < s->n_recursos * 3; j++) printf("  ---------");
    printf("\n");

    for (i = 0; i < s->n_processos; i++) {
        printf("%-10s", s->processos[i].nome);
        for (j = 0; j < s->n_recursos; j++)
            printf("  %8d ", s->processos[i].alocacao[j]);
        for (j = 0; j < s->n_recursos; j++)
            printf("  %8d ", s->processos[i].maximo[j]);
        for (j = 0; j < s->n_recursos; j++)
            printf("  %8d ", s->processos[i].necessidade[j]);
        printf("\n");
    }

    printf("\nRecursos disponíveis: ");
    for (j = 0; j < s->n_recursos; j++)
        printf("R%d=%d  ", j, s->disponiveis[j]);
    printf("\n");
}

void imprimir_resultado(Sistema *s, int seguro) {
    int i;
    printf("\n============================================================\n");
    if (seguro) {
        printf("RESULTADO: ESTADO SEGURO - Não há risco de deadlock!\n");
        printf("Sequência segura encontrada: ");
        for (i = 0; i < s->tam_sequencia; i++) {
            printf("%s", s->processos[s->sequencia[i]].nome);
            if (i < s->tam_sequencia - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        printf("RESULTADO: ESTADO INSEGURO - Risco de deadlock!\n");
        printf("Não foi possível encontrar uma sequência de execução segura.\n");
    }
    printf("============================================================\n\n");
}

void entrada_manual(Sistema *s) {
    int i, j;

    printf("\n=== ALGORITMO DO BANQUEIRO ===\n\n");
    printf("Número de processos: ");
    scanf("%d", &s->n_processos);

    printf("Número de tipos de recursos: ");
    scanf("%d", &s->n_recursos);

    
    printf("\nRecursos disponíveis (digite %d valores):\n", s->n_recursos);
    for (j = 0; j < s->n_recursos; j++) {
        printf("  Recurso R%d: ", j);
        scanf("%d", &s->disponiveis[j]);
    }

    
    for (i = 0; i < s->n_processos; i++) {
        sprintf(s->processos[i].nome, "P%d", i);
        s->processos[i].finalizado = 0;

        printf("\n--- Processo P%d ---\n", i);

        printf("  Alocação atual (%d recursos):\n", s->n_recursos);
        for (j = 0; j < s->n_recursos; j++) {
            printf("    R%d: ", j);
            scanf("%d", &s->processos[i].alocacao[j]);
        }

        printf("  Demanda máxima (%d recursos):\n", s->n_recursos);
        for (j = 0; j < s->n_recursos; j++) {
            printf("    R%d: ", j);
            scanf("%d", &s->processos[i].maximo[j]);
        }
    }
}

void carregar_exemplo_atividade(Sistema *s) {
    
    s->n_processos = 3;
    s->n_recursos  = 1;
    s->disponiveis[0] = 1;

    strcpy(s->processos[0].nome, "P1");
    s->processos[0].alocacao[0]  = 2;
    s->processos[0].maximo[0]    = 4;

    strcpy(s->processos[1].nome, "P2");
    s->processos[1].alocacao[0]  = 3;
    s->processos[1].maximo[0]    = 5;

    strcpy(s->processos[2].nome, "P3");
    s->processos[2].alocacao[0]  = 1;
    s->processos[2].maximo[0]    = 3;

    int i;
    for (i = 0; i < s->n_processos; i++)
        s->processos[i].finalizado = 0;
}


void carregar_exemplo_seguro(Sistema *s) {
    
    int i;
    int aloc[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int maxi[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    char nomes[5][10] = {"P0","P1","P2","P3","P4"};

    s->n_processos = 5;
    s->n_recursos  = 3;
    s->disponiveis[0] = 3;
    s->disponiveis[1] = 3;
    s->disponiveis[2] = 2;

    for (i = 0; i < 5; i++) {
        strcpy(s->processos[i].nome, nomes[i]);
        s->processos[i].alocacao[0] = aloc[i][0];
        s->processos[i].alocacao[1] = aloc[i][1];
        s->processos[i].alocacao[2] = aloc[i][2];
        s->processos[i].maximo[0]   = maxi[i][0];
        s->processos[i].maximo[1]   = maxi[i][1];
        s->processos[i].maximo[2]   = maxi[i][2];
        s->processos[i].finalizado  = 0;
    }
}

int main() {
    Sistema s;
    int opcao, seguro;

    printf("====================================================\n");
    printf("     SIMULADOR - ALGORITMO DO BANQUEIRO\n");
    printf("     Sistemas Operacionais - IFNMG Januaria\n");
    printf("====================================================\n\n");

    printf("Escolha uma opcao:\n");
    printf("  1 - Exemplo da atividade (estado INSEGURO)\n");
    printf("  2 - Exemplo classico seguro (5 processos / 3 recursos)\n");
    printf("  3 - Entrada manual\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            carregar_exemplo_atividade(&s);
            break;
        case 2:
            carregar_exemplo_seguro(&s);
            break;
        default:
            entrada_manual(&s);
            break;
    }

    calcular_necessidades(&s);
    imprimir_tabela(&s);

    seguro = verificar_estado_seguro(&s);
    imprimir_resultado(&s, seguro);

    return 0;
}
