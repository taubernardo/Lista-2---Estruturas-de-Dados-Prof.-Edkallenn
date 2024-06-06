/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vetor[], int tamanho, int *numComparacoes, int *numTrocas) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            (*numComparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                (*numTrocas)++;
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void gerarValoresAleatorios(int vetor[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Valores aleatórios entre 0 e 99
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    gerarValoresAleatorios(vetor, tamanho);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

