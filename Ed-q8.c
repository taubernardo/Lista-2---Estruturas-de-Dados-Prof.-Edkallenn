/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double parteReal;
    double parteImaginaria;
} Complexo;

Complexo *criarComplexo(double real, double imaginaria)
{
    Complexo *numComplexo = (Complexo *)malloc(sizeof(Complexo));
    if (numComplexo != NULL)
    {
        numComplexo->parteReal = real;
        numComplexo->parteImaginaria = imaginaria;
    }
    return numComplexo;
}

void destruirComplexo(Complexo *numComplexo)
{
    free(numComplexo);
}

void lerComplexo(Complexo *numComplexo)
{
    printf("Digite a parte real: ");
    scanf("%lf", &numComplexo->parteReal);
    printf("Digite a parte imaginaria: ");
    scanf("%lf", &numComplexo->parteImaginaria);
}

void somarComplexos(Complexo *resultado, Complexo *num1, Complexo *num2)
{
    resultado->parteReal = num1->parteReal + num2->parteReal;
    resultado->parteImaginaria = num1->parteImaginaria + num2->parteImaginaria;
}

void subtrairComplexos(Complexo *resultado, Complexo *num1, Complexo *num2)
{
    resultado->parteReal = num1->parteReal - num2->parteReal;
    resultado->parteImaginaria = num1->parteImaginaria - num2->parteImaginaria;
}

void multiplicarComplexos(Complexo *resultado, Complexo *num1, Complexo *num2)
{
    resultado->parteReal = num1->parteReal * num2->parteReal - num1->parteImaginaria * num2->parteImaginaria;
    resultado->parteImaginaria = num1->parteReal * num2->parteImaginaria + num1->parteImaginaria * num2->parteReal;
}

void dividirComplexos(Complexo *resultado, Complexo *num1, Complexo *num2)
{
    double denominador = num2->parteReal * num2->parteReal + num2->parteImaginaria * num2->parteImaginaria;
    resultado->parteReal = (num1->parteReal * num2->parteReal + num1->parteImaginaria * num2->parteImaginaria) / denominador;
    resultado->parteImaginaria = (num1->parteImaginaria * num2->parteReal - num1->parteReal * num2->parteImaginaria) / denominador;
}

void mostrarComplexo(Complexo *numComplexo)
{
    printf("(%lf,%lf)\n", numComplexo->parteReal, numComplexo->parteImaginaria);
}

int main()
{
    Complexo *num1, *num2, *resultado;

    // Criando dois números complexos
    num1 = criarComplexo(2.0, 3.0);
    num2 = criarComplexo(1.0, -2.0);
    resultado = criarComplexo(0.0, 0.0);

    // Operações
    somarComplexos(resultado, num1, num2);
    printf("Soma: ");
    mostrarComplexo(resultado);

    subtrairComplexos(resultado, num1, num2);
    printf("Subtracao: ");
    mostrarComplexo(resultado);

    multiplicarComplexos(resultado, num1, num2);
    printf("Multiplicacao: ");
    mostrarComplexo(resultado);

    dividirComplexos(resultado, num1, num2);
    printf("Divisao: ");
    mostrarComplexo(resultado);

    // Liberando a memória alocada
    destruirComplexo(num1);
    destruirComplexo(num2);
    destruirComplexo(resultado);

    return 0;
}
