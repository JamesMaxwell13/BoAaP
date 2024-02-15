#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    scanf("%d", &size);

    int** a = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        a[i] = (int*)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            a[i][k] = i * size + k + 1;
        }
    }

    for (int i = 0; i < size * 2 - 1; i++) {
        if (i % 2 == 0) {
            for (int k = 0; k < size; k++) {
                for (int j = 0; j < size; j++) {
                    if (k + j == i) {
                        printf("%d ", a[k][j]);
                    }
                }
            }
        }
        else {
            for (int k = size - 1; k >= 0; k--) {
                for (int j = size - 1; j >= 0; j--) {
                    if (k + j == i) {
                        printf("%d ", a[k][j]);
                    }
                }
            }
        }
    }


    return 0;
}