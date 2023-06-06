#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int ChecarEscolha(char *escolha) {
    if (strcmp(escolha, "s") == 0 || strcmp(escolha, "sim") == 0 || strcmp(escolha, "S") == 0 || strcmp(escolha, "Sim") == 0)
        return 1;
    return 0;
}

void Imprimir(int **matGrafos, int tamGrafo){


    printf("\nEssa é a matriz que representa esse grafo:\n");
    for (int i = 0; i < tamGrafo; i++) {
        for (int j = 0; j < tamGrafo; j++) {
                printf("%d ", matGrafos[i][j]);
        }
        printf("\n");
    }
}

int VerificarCompleto(int **matGrafos, int tamGrafo) {
    for (int i = 0; i < tamGrafo; i++) {
        if(matGrafos[i][i] != 0)
            return 0;//false
        for (int j = 0; j < tamGrafo; j++) {
            if(i != j && matGrafos[i][j] != 1)
                return 0;//false
        }
    }
    return 1;//true
}

int VerificarMultigrafo(int **matGrafos, int tamGrafo) {
    for (int i = 0; i < tamGrafo; i++) {
        for (int j = 0; j < tamGrafo; j++) {
            if (matGrafos[i][j] > 1) 
                return 1;
        }
    }
    return 0;
}

int ContarLacos(int **matGrafos, int tamGrafo) {
    int count = 0;
    for (int i = 0; i < tamGrafo; i++) {
        if (matGrafos[i][i] > 0) 
            count++;
    }
    return count;
}

int ContarVerticesFolhas(int **matGrafos, int tamGrafo) {
    int count = 0;
    for (int i = 0; i < tamGrafo; i++) {
        int isFolha = 0;
        for (int j = 0; j < tamGrafo; j++) {
            if (i != j && matGrafos[i][j] > 0 && !isFolha) 
                isFolha = 1;
            else if(isFolha && matGrafos[i][j] > 0){
                isFolha = 0;
                break;
            }
        }
        if (isFolha) 
            count++;
    }
    return count;
}

int VerificarVerticeIsolado(int **matGrafos, int tamGrafo) {
    for (int i = 0; i < tamGrafo; i++) {
        int isIsolado = 1;
        for (int j = 0; j < tamGrafo; j++) {
            if (matGrafos[i][j] > 0 || matGrafos[j][i] > 0) {
                isIsolado = 0;
                break;
            }
        }
        if (isIsolado) 
            return 1;
    }
    return 0;
}
int VerificarBipartido(int **matGrafos, int tamGrafo) {
    int lado[tamGrafo]; // Vetor de lados: 0 para não visitado, 1 para lado 1, -1 para lado -1

    for (int i = 0; i < tamGrafo; i++) {
        lado[i] = 0; // Define todas as lados como não visitado (0)
    }

    for (int i = 0; i < tamGrafo; i++) {
        if (lado[i] == 0) {
            lado[i] = 1; // Define a lado 1 para o vértice atual
        }
        for (int j = 0; j < tamGrafo; j++) {
            if (matGrafos[i][j] != 0) {
                if (lado[j] == lado[i]) {
                    return 0; // Conflito de ladoes, grafo não é bipartido
                } else if (lado[j] == 0) {
                    lado[j] = -lado[i]; // Define a lado oposta para o vértice adjacente
                }
            }
        }
        
    }

    return 1; // Não houve conflito de lados, grafo é bipartido
}



int VerificarPlanar(int **matGrafos, int tamGrafo, int arestas) {
    if(VerificarBipartido(matGrafos, tamGrafo)){
        if(arestas <= 2*tamGrafo - 4)
            return 1;
    }
    else{
        if(arestas <= 3*tamGrafo - 6)
            return 1;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");

    int **matGrafos,tamGrafo, arestas = 0;
    printf("\n\t\tDigite quantos vértices tem nesse grafo: ");
    scanf("%d", &tamGrafo);
    //int matGrafos[tamGrafo][tamGrafo];

    matGrafos = malloc(tamGrafo * sizeof(int*));

    for(int i=0;i<tamGrafo;i++)
        matGrafos[i] = malloc(tamGrafo * sizeof(int*));

    char escolha[10];
    printf("\n\t\tO grafo é direcionado? (s/n): ");
    scanf("%s", escolha);

    for (int i = 0; i < tamGrafo; i++) {
        for (int j = 0; j < tamGrafo; j++) {
            matGrafos[i][j] = 0;
        }
    }

    if (ChecarEscolha(escolha) == 1) {
        for (int i = 0; i < tamGrafo; i++) {
            for (int j = 0; j < tamGrafo; j++) {
                if (i == j)
                    printf("\n\t\tQuantos laços o vértice %d tem? ", i);
                else
                    printf("\n\t\tQuantas arestas o vértice %d tem apontando para o vértice %d? ", i, j);

                scanf("%d", &matGrafos[i][j]);
                arestas += matGrafos[i][j];
            }
        }
    } else {
        for (int i = 0; i < tamGrafo; i++) {
            for (int j = i; j < tamGrafo; j++) {
                if(i <= j){
                    if (i == j)
                        printf("\n\t\tQuantos laços o vértice %d tem? ", i);
                    else
                        printf("\n\t\tQuantas arestas o vértice %d tem ligando ao vértice %d? ", i, j);
                    scanf("%d", &matGrafos[i][j]);
                    matGrafos[j][i] = matGrafos[i][j];
                    arestas += matGrafos[i][j];
                }
            }
        }
    }

    Imprimir(matGrafos,tamGrafo);

    int opcao;
    do {
        printf("\nMenu de Verificação do Grafo:\n");
        printf("1 - Verificar se o grafo é completo\n");
        printf("2 - Verificar se é um multigrafo\n");
        printf("3 - Quantos laços existem?\n");
        printf("4 - Quantos vértices folhas existem?\n");
        printf("5 - Verificar se existe vértice isolado\n");
        printf("6 - Verificar se é possível ser planar\n");
        printf("0 - Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao) {
            case 1:
                if (VerificarCompleto(matGrafos, tamGrafo))
                    printf("O grafo é completo.\n");
                else
                    printf("O grafo não é completo.\n");
                break;
            case 2:
                if (VerificarMultigrafo(matGrafos, tamGrafo))
                    printf("O grafo é um multigrafo.\n");
                else
                    printf("O grafo não é um multigrafo.\n");
                break;
            case 3:
                printf("Existem %d laços no grafo.\n", ContarLacos(matGrafos, tamGrafo));
                break;
            case 4:
                printf("Existem %d vértices folhas no grafo.\n", ContarVerticesFolhas(matGrafos, tamGrafo));
                break;
            case 5:
                if (VerificarVerticeIsolado(matGrafos, tamGrafo))
                    printf("Existe pelo menos um vértice isolado no grafo.\n");
                else
                    printf("Não existem vértices isolados no grafo.\n");
                break;
            case 6:
                if (VerificarPlanar(matGrafos, tamGrafo, arestas))
                    printf("O grafo é possível ser planar.\n");
                else
                    printf("O grafo não é possível ser planar.\n");
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
