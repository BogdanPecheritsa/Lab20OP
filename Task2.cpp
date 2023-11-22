#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void addRow(int*** matrix, int* rows, int cols, int rowNum) {
    *matrix = (int**)realloc(*matrix, (*rows + 1) * sizeof(int*));
    (*matrix)[*rows] = (int*)malloc(cols * sizeof(int));

    printf("Введіть новий рядок:\n");
    for (int j = 0; j < cols; ++j) {
        printf("Елемент [%d][%d]: ", *rows + 1, j + 1);
        scanf_s("%d", &(*matrix)[*rows][j]);
    }

    ++(*rows);
}

void deleteColumn(int*** matrix, int* rows, int* cols) {
    int minColumn = 0;
    int minValue = (*matrix)[0][0];

    for (int j = 0; j < *cols; ++j) {
        for (int i = 0; i < *rows; ++i) {
            if ((*matrix)[i][j] < minValue) {
                minValue = (*matrix)[i][j];
                minColumn = j;
            }
        }
    }

    for (int i = 0; i < *rows; ++i) {
        for (int j = minColumn; j < *cols - 1; ++j) {
            (*matrix)[i][j] = (*matrix)[i][j + 1];
        }
    }

    *matrix = (int**)realloc(*matrix, *cols * sizeof(int*));
    --(*cols);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int** matrix = NULL;
    int rows = 0;
    int cols;

    printf("Введіть кількість стовпців масиву: ");
    scanf_s("%d", &cols);

    while (1) {
        int choice;

        printf("\n1. Додати рядок\n");
        printf("2. Видалити стовпець з мінімальним елементом\n");
        printf("3. Завершити програму\n");
        printf("Ваш вибір: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addRow(&matrix, &rows, cols, rows + 1);
            break;
        case 2:
            if (cols > 0) {
                deleteColumn(&matrix, &rows, &cols);
                printf("Стовпець видалено\n");
            }
            else {
                printf("Масив порожній\n");
            }
            break;
        case 3:
            for (int i = 0; i < rows; ++i) {
                free(matrix[i]);
            }
            free(matrix);
            return 0;
        default:
            printf("Невірний вибір. Спробуйте ще раз.\n");
        }
    }
}