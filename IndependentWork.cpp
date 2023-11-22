#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void setConsoleEncoding() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void getInputArray(int** arr, int* size, char name) {
    printf("Введіть розмір масиву %c: ", name);
    scanf_s("%d", size);

    *arr = (int*)malloc(*size * sizeof(int));

    printf("Введіть елементи масиву %c:\n", name);
    for (int i = 0; i < *size; ++i) {
        printf("Елемент %c[%d]: ", name, i + 1);
        scanf_s("%d", &(*arr)[i]);
    }
}

void mergeArrays(int* x, int sizeX, int* y, int sizeY, int** merged, int* sizeMerged) {
    *sizeMerged = sizeX + sizeY;
    *merged = (int*)malloc(*sizeMerged * sizeof(int));

    for (int i = 0; i < sizeX; ++i) {
        (*merged)[i] = x[i];
    }

    for (int i = 0; i < sizeY; ++i) {
        (*merged)[sizeX + i] = y[i];
    }
}

void findCommonElements(int* x, int sizeX, int* y, int sizeY, int** common, int* sizeCommon) {
    *sizeCommon = (sizeX < sizeY) ? sizeX : sizeY;
    *common = (int*)malloc(*sizeCommon * sizeof(int));

    int count = 0;

    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            if (x[i] == y[j]) {
                (*common)[count++] = x[i];
                break;
            }
        }
    }

    *sizeCommon = count;
}

void printArray(int* arr, int size, const char* name) {
    printf("\nМасив %s (розмір %d):\n", name, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setConsoleEncoding();

    int* x, * y, * merged, * common;
    int sizeX, sizeY, sizeMerged, sizeCommon;

    getInputArray(&x, &sizeX, 'x');
    getInputArray(&y, &sizeY, 'y');

    mergeArrays(x, sizeX, y, sizeY, &merged, &sizeMerged);
    findCommonElements(x, sizeX, y, sizeY, &common, &sizeCommon);

    printArray(x, sizeX, "x");
    printArray(y, sizeY, "y");
    printArray(merged, sizeMerged, "з обох масивів");

    if (sizeCommon > 0) {
        printArray(common, sizeCommon, "спільні елементи");
    }
    else {
        printf("\nНемає спільних елементів.\n");
    }

    free(x);
    free(y);
    free(merged);
    free(common);

    return 0;
}