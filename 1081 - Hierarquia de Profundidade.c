#include <stdio.h>

int verificados[20];        // Array para marcar vértices visitados
int matriz[20][20];    // Matriz de adjacência para representar o grafo

int a = 0;

void PathR(int v, int pronfundidade) {
    verificados[v] = 1;     // Marca o vértice como visitado

    for (int w = 0; w < 20; w++) {
        if (matriz[v][w] == 1) {
            a = 1;
            if(a == 1){

            }
            // Imprime espaços em branco de acordo com a profundidade
            for (int i = 0; i < pronfundidade; i++) {
                printf(" ");
            }
            // Imprime a aresta no formato "v-w"
            printf("%d-%d", v, w);
            
            if (verificados[w] == -1) {
                // Se o vértice w não foi visitado, chama recursivamente PathR para ele
                verificados[w] = 0;     // Marca w como visitado (mas não finalizado)
                printf(" pathR(G,%d)\n", w);
                PathR(w, pronfundidade + 2);    // Chama recursivamente com incremento na profundidade
            } else {
                printf("\n");   // Se w já foi visitado, imprime uma quebra de linha
            }
        }
    }
}

int main() {
    int N, V, E;

    scanf("%d", &N);  // Lê o número total de casos de teste

    for (int qtdDeCasos = 1; qtdDeCasos <= N; qtdDeCasos++) {
        scanf("%d", &V);    // Lê o número de vértices do caso de teste atual
        scanf("%d", &E);    // Lê o número de arestas do caso de teste atual

        // Limpa a matriz de matrizacência e o array de vértices visitados
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                matriz[i][j] = 0;
            }
            verificados[i] = -1;
        }

        // Lê as arestas e preenche a matriz de matrizacência
        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d", &u);
            scanf("%d", &v);
            matriz[u][v] = 1;
        }

        printf("Caso %d:\n", qtdDeCasos);

        // Executa o algoritmo PathR para cada vértice não visitado
        for (int i = 0; i < V; i++) {
            a = 0;
            if (verificados[i] == -1) {
                PathR(i, 2);
                if(a == 1){
                    printf("\n");
                }
            }
        }

        // Redefine o estado das variáveis verificados e matriz para o próximo caso de teste
        for (int i = 0; i < V; i++) {
            verificados[i] = -1;
            for (int j = 0; j < V; j++) {
                matriz[i][j] = 0;
            }
        }
    }

    return 0;
}
