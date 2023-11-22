#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int matrix[4][4];

    printf("������ �������� ������� 4x4:\n");

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("������� [%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    printf("\n������ �������� ���� ������� �������:\n");

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i < j) {
                printf("������ �������� [%d][%d]: %p\n", i + 1, j + 1, (void*)&matrix[i][j]);
            }
        }
    }

    return 0;
}