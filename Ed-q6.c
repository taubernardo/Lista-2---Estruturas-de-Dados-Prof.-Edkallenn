/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <math.h>

double calcularRaiz(double numero) {
    double estimativa = numero / 2.0;

    while (fabs(estimativa * estimativa - numero) > 0.0001) {
        double temp = estimativa;
        estimativa = 0.5 * (estimativa + numero / estimativa);
        if (fabs(temp - estimativa) < 0.0001) break;
    }

    return estimativa;
}

int main() {
    double numero;

    printf("Digite um numero para calcular a raiz quadrada: ");
    scanf("%lf", &numero);

    if (numero < 0) {
        printf("Nao e possivel calcular a raiz quadrada de um numero negativo.\n");
    } else {
        double raiz = calcularRaiz(numero);
        printf("A raiz quadrada de %.4lf e aproximadamente %.4lf\n", numero, raiz);
    }

    return 0;
}
