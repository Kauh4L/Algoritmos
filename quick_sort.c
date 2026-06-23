#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {

    int n = 1000;

    srand(time(NULL));

    for(int j = 0; j < 10; j++) {

        int vetor[n];

        // Preenche o vetor com números aleatórios
        for(int i = 0; i < n; i++) {
            vetor[i] = rand() % 10000;
        }

        clock_t inicio, fim;

        inicio = clock();

        quickSort(vetor, 0, n - 1);

        fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("n = %d -> Tempo: %f segundos\n", n, tempo);

        n = n - 100;
    }

    return 0;
}
