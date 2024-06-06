/*
** Função :
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void findPrimes(int num)
{
    for (int i = 2; i <= num / 2; i++)
    {
        if (isPrime(i) && isPrime(num - i))
        {
            printf("%d = %d + %d\n", num, i, num - i);
            return;
        }
    }
    printf("Couldn't find %d\n", num);
}

int main()
{
    int N;

    printf("Enter an integer N: ");
    scanf("%d", &N);

    for (int num = 4; num <= N; num += 2)
    {
        findPrimes(num);
    }

    return 0;
}
