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
}

int main()
{
    for (int num = 700; num <= 1100; num += 2)
    {
        findPrimes(num);
    }
    return 0;
}
