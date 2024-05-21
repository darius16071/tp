/*
Aplicația 11.3: Definim reducerea unei matrici cu elemente întregi ca fiind valoarea calculată astfel: dacă matricea
nu are niciun element, reducerea este 0. Dacă matricea are un element, reducerea este valoarea acelui element.
Pentru orice alte cazuri, matricea se subîmparte în 4 matrici prin tăierea ei în cruce, prin mijlocul matricii. Reducerea
va fi maximul reducerilor celor două matrici superioare, minus minimul reducerilor celor două matrici inferioare. Să
se calculeze reducerea unei matrici de dimensiuni m,n citită de la tastatură.
divide et impera
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) 
{
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if(a>b)
        return b;
    else
        return a;
}

int reduceMatrix(int **matrix, int startRow, int endRow, int startCol, int endCol) {
    if (startRow > endRow || startCol > endCol) {
        return 0;
    }

    if (startRow == endRow && startCol == endCol) {
        return matrix[startRow][startCol];
    }

    int midRow = (startRow + endRow) / 2;
    int midCol = (startCol + endCol) / 2;

    int topLeft = reduceMatrix(matrix, startRow, midRow, startCol, midCol);
    int topRight = reduceMatrix(matrix, startRow, midRow, midCol + 1, endCol);
    int bottomLeft = reduceMatrix(matrix, midRow + 1, endRow, startCol, midCol);
    int bottomRight = reduceMatrix(matrix, midRow + 1, endRow, midCol + 1, endCol);

    int topMax = max(topLeft, topRight);
    int bottomMin = min(bottomLeft, bottomRight);

    return topMax - bottomMin;
}

int main() {
    int m, n;
    printf("Introduceți dimensiunile matricei (m și n): ");
    scanf("%d %d", &m, &n);

    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Introduceți elementele matricei:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int reduction = reduceMatrix(matrix, 0, m - 1, 0, n - 1);
    printf("Reducerea matricei este: %d\n", reduction);

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
