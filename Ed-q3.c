/*
** Função :
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char code[4];
    char city[51];
    char country[31];
    float fee;
    int capacity;
} Airport;

void readAirport(Airport *aero)
{
    printf("Enter code: ");
    scanf(" %3s", aero->code);
    printf("Enter city: ");
    scanf(" %[^\n]", aero->city);
    printf("Enter country: ");
    scanf(" %[^\n]", aero->country);
    printf("Enter fee: ");
    scanf("%f", &aero->fee);
    printf("Enter capacity: ");
    scanf("%d", &aero->capacity);
}

void writeAirport(Airport *aero)
{
    printf("Code: %s\n", aero->code);
    printf("City: %s\n", aero->city);
    printf("Country: %s\n", aero->country);
    printf("Fee: %.2f\n", aero->fee);
    printf("Capacity: %d\n", aero->capacity);
}

void removeAirport(Airport **airports, int *size, int index)
{
    free(airports[index]);
    for (int i = index; i < *size - 1; i++)
    {
        airports[i] = airports[i + 1];
    }
    (*size)--;
    airports = realloc(airports, (*size) * sizeof(Airport *));
}

int main()
{
    int option, size = 0;
    Airport **airports = NULL;

    do
    {
        printf("\nMenu:\n");
        printf("1. Add airport\n");
        printf("2. List airports\n");
        printf("3. Remove airport\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            size++;
            airports = realloc(airports, size * sizeof(Airport *));
            airports[size - 1] = malloc(sizeof(Airport));
            readAirport(airports[size - 1]);
            break;
        case 2:
            for (int i = 0; i < size; i++)
            {
                printf("\nAirport %d:\n", i + 1);
                writeAirport(airports[i]);
            }
            break;
        case 3:
            if (size == 0)
            {
                printf("No airport to remove.\n");
            }
            else
            {
                int index;
                printf("Enter the index of the airport to be removed (1 to %d): ", size);
                scanf("%d", &index);
                if (index < 1 || index > size)
                {
                    printf("Invalid index.\n");
                }
                else
                {
                    removeAirport(airports, &size, index - 1);
                    printf("Airport removed.\n");
                }
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
        }
    } while (option != 4);

    for (int i = 0; i < size; i++)
    {
        free(airports[i]);
    }
    free(airports);
    return 0;
}
