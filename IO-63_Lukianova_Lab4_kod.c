#include <stdio.h>

#define N 7

void printMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%5.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double matrix[N][N] = {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.5},
        {0.0, 0.0, 0.0, 0.0, 0.0, 2.5, 0.0},
        {0.0, 0.0, 0.0, 0.0, 3.5, 0.0, 0.0},
        {0.0, 0.0, 0.0, 3.5, 0.0, 0.0, 0.0},
        {0.0, 0.0, 3.5, 0.0, 0.0, 0.0, 0.0},
        {0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {6.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    };

    printf("Initial matrix %dx%d:\n", N, N);
    printMatrix(matrix);

    double X = 4.2;
    printf("\nTarget value X = %.1f\n", X);

    int L = 0;
    int R = N - 1;
    int steps = 0;

    while (L < R) {
        steps++;
        int m = L + (R - L) / 2;

        if (matrix[m][N - 1 - m] < X) {
            L = m + 1;
        } else {
            R = m;
        }
    }
    steps++;

    if (matrix[L][N - 1 - L] == X) {
        printf("\nElement found!\n");
        printf("Index in diagonal (leftmost): %d\n", L);
        printf("Coordinates in matrix: row %d, column %d\n", L, N - 1 - L);
        printf("Binary search steps count: %d\n", steps);
    } else {
        printf("\nElement %.1f not found in the secondary diagonal.\n", X);
        printf("Binary search steps count: %d\n", steps);
    }

    return 0;
}