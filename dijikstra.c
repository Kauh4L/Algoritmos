#include <stdio.h>
#include <limits.h>

#define V 5

int menorDistancia(int dist[], int visitado[]) {
    int min = INT_MAX;
    int indice = -1;

    for(int v = 0; v < V; v++) {
        if(!visitado[v] && dist[v] <= min) {
            min = dist[v];
            indice = v;
        }
    }

    return indice;
}

void dijkstra(int grafo[V][V], int origem) {

    int dist[V];
    int visitado[V];

    // inicializa tudo
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visitado[i] = 0;
    }

    dist[origem] = 0;

    // processo principal
    for(int i = 0; i < V - 1; i++) {

        int u = menorDistancia(dist, visitado);
        visitado[u] = 1;

        for(int v = 0; v < V; v++) {

            if(!visitado[v] &&
               grafo[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + grafo[u][v] < dist[v]) {

                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    // saída final
    printf("\nDistancias a partir da origem:\n");
    for(int i = 0; i < V; i++) {
        printf("Vertice %d -> %d\n", i, dist[i]);
    }
}

int main() {

    int grafo[V][V] = {
        {0, 4, 2, 0, 0},
        {4, 0, 1, 5, 0},
        {2, 1, 0, 8, 10},
        {0, 5, 8, 0, 2},
        {0, 0, 10, 2, 0}
    };

    dijkstra(grafo, 0);

    return 0;
}