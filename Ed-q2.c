/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char birthDate[11];
    char ID[20];
    char hireDate[11];
    double salary;
} Employee;

void readData(Employee *emp) {
    printf("Enter name: ");
    scanf(" %[^\n]", emp->name);
    printf("Enter birth date (dd/mm/yyyy): ");
    scanf(" %[^\n]", emp->birthDate);
    printf("Enter ID: ");
    scanf(" %[^\n]", emp->ID);
    printf("Enter hire date (dd/mm/yyyy): ");
    scanf(" %[^\n]", emp->hireDate);
    printf("Enter salary: ");
    scanf("%lf", &emp->salary);
}

void displayData(Employee emp) {
    printf("Name: %s\n", emp.name);
    printf("Birth Date: %s\n", emp.birthDate);
    printf("ID: %s\n", emp.ID);
    printf("Hire Date: %s\n", emp.hireDate);
    printf("Salary: %.2lf\n", emp.salary);
}

void removeEmployee(Employee *emps, int index, int *size) {
    for (int i = index; i < *size - 1; i++) {
        emps[i] = emps[i + 1];
    }
    (*size)--;
    emps = realloc(emps, (*size) * sizeof(Employee));
}

int main() {
    int option, size = 0;
    Employee *employees = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Add employee\n");
        printf("2. List employees\n");
        printf("3. Remove employee\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                size++;
                employees = realloc(employees, size * sizeof(Employee));
                readData(&employees[size - 1]);
                break;
            case 2:
                for (int i = 0; i < size; i++) {
                    printf("\nEmployee %d:\n", i + 1);
                    displayData(employees[i]);
                }
                break;
            case 3:
                if (size == 0) {
                    printf("No employee to remove.\n");
                } else {
                    int index;
                    printf("Enter the index of the employee to be removed (1 to %d): ", size);
                    scanf("%d", &index);
                    if (index < 1 || index > size) {
                        printf("Invalid index.\n");
                    } else {
                        removeEmployee(employees, index - 1, &size);
                        printf("Employee removed.\n");
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

    free(employees);
    return 0;
}
