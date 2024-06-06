/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocarElementos(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[(inicio + fim) / 2]; // Pivô é o elemento central
    int esquerda = inicio;
    int direita = fim;

    while (esquerda <= direita) {
        while (vetor[esquerda] < pivo) {
            esquerda++;
        }
        while (vetor[direita] > pivo) {
            direita--;
        }
        if (esquerda <= direita) {
            trocarElementos(&vetor[esquerda], &vetor[direita]);
            esquerda++;
            direita--;
        }
    }

    return esquerda;
}

void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(vetor, inicio, fim);
        quicksort(vetor, inicio, indicePivo - 1); // Ordena a metade esquerda
        quicksort(vetor, indicePivo, fim); // Ordena a metade direita
    }
}

void gerarValoresAleatorios(int vetor[], int tamanho, int limite) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % limite;
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 10; // Tamanho do vetor
    int limite = 100; // Limite superior para os valores aleatórios
    int vetor[tamanho];

    gerarValoresAleatorios(vetor, tamanho, limite);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    quicksort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
