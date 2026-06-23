#include "algoritmos.h"
#include <stdio.h>
#include <limits.h>

/* BUBBLE SORT */
void bubbleSort(int vetor[], int n) {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

/* QUICK SORT */
int particao(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++) {
        if(vetor[j] < pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return i + 1;
}

void quickSort(int vetor[], int inicio, int fim) {
    if(inicio < fim) {
        int p = particao(vetor, inicio, fim);
        quickSort(vetor, inicio, p - 1);
        quickSort(vetor, p + 1, fim);
    }
}

/* DIJKSTRA */
int menorDistancia(int dist[], int visitado[]) {
    int min = INT_MAX, indice = -1;

    for(int v = 0; v < 5; v++) {
        if(!visitado[v] && dist[v] <= min) {
            min = dist[v];
            indice = v;
        }
    }

    return indice;
}

void dijkstra(int grafo[5][5], int origem) {

    int dist[5];
    int visitado[5];

    for(int i = 0; i < 5; i++) {
        dist[i] = INT_MAX;
        visitado[i] = 0;
    }

    dist[origem] = 0;

    for(int i = 0; i < 4; i++) {

        int u = menorDistancia(dist, visitado);
        visitado[u] = 1;

        for(int v = 0; v < 5; v++) {
            if(!visitado[v] &&
               grafo[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + grafo[u][v] < dist[v]) {

                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    printf("\nDijkstra resultado:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }
}