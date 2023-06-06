#include <stdio.h>
#include <locale.h>
#include <string.h>

int ChecarEscolha(char * escolha){
    if(strcmp(escolha, "s") == 0 || strcmp(escolha, "sim") == 0 || strcmp(escolha, "S") == 0 || strcmp(escolha, "Sim") == 0 )
        return 1;
    return 0;
}

int main() {  
    setlocale(LC_ALL, "Portuguese_Brasil");

    int tamGrafo;
    printf("\n\t\tDigite quantos vertices tem nesse grafo: ");
    scanf("%d", &tamGrafo);
    int matGrafos[tamGrafo][tamGrafo];

    char escolha[10];
    printf("\n\t\tO grafo e direcionado?: ");
    scanf("%s", escolha);

    for(int i=0;i<tamGrafo;i++){
        for(int j=0;j<tamGrafo;j++){
            matGrafos[i][j] = 0;
        }
    }

    if(ChecarEscolha(escolha) == 1){
        for(int i=0;i<tamGrafo;i++){
            for(int j=0;j<tamGrafo;j++){
                if(i == j)
                    printf("\n\t\tQuantos lacos o vertice %d tem? ",i);
                else
                    printf("\n\t\tQuantas arestas o vertice %d tem apontando para o vertice %d? ",i,j);
                
                scanf("%d", &matGrafos[i][j]);
            }
        }
        
        printf("\nEssa e a matriz que representa esse grafo\n");
        for(int i=0;i<tamGrafo;i++){
            for(int j=0;j<tamGrafo;j++){
                printf("%d ", matGrafos[i][j]);
            }
            printf("\n");
        }
    }

    else{
        for(int i=0;i<tamGrafo;i++){
            for(int j=i;j<tamGrafo;j++){
                if(i == j)
                    printf("\n\t\tQuantos lacos o vertice %d tem? ",i);
                else
                    printf("\n\t\tQuantas arestas o vertice %d tem ligando ao vertice %d? ",i,j);
                scanf("%d", &matGrafos[i][j]);
            }
        }

        printf("\nEssa e a matriz que representa esse grafo\n");
        for(int i=0;i<tamGrafo;i++){
            for(int j=0;j<tamGrafo;j++){
                if(i > j)
                    printf("%d ", matGrafos[j][i]);
                else
                    printf("%d ", matGrafos[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}