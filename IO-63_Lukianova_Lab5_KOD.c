#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 7
#define COLS 8

void insertion_sort_barrier_desc(int row[COLS + 1], int n) {
    for (int i = 2; i <= n; i++) {
        int key = row[i];
        row[0] = key;

        int j = i - 1;
        while (row[j] < key) {
            row[j + 1] = row[j];
            j--;
        }
        row[j + 1] = key;
    }
}

void sort_matrix_rows_desc(int matrix[ROWS][COLS + 1], int m, int n) {
    for (int i = 0; i < m; i++) {
        insertion_sort_barrier_desc(matrix[i], n);
    }
}

void print_matrix(const int matrix[ROWS][COLS + 1], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_sorted_non_increasing(int matrix[ROWS][COLS + 1], int m, int n) {
    for (int i = 0; i < m; i++) {
        int start_val = 100 + i * 10;
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = start_val - j * 3;
        }
        matrix[i][0] = 0;
    }
}

void fill_random(int matrix[ROWS][COLS + 1], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = rand() % 101 - 20;
        }
        matrix[i][0] = 0;
    }
}

void fill_reverse_sorted(int matrix[ROWS][COLS + 1], int m, int n) {
    for (int i = 0; i < m; i++) {
        int start_val = i * 5;
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = start_val + j * 4;
        }
        matrix[i][0] = 0;
    }
}

int main(void) {
    srand((unsigned int)time(NULL));
    int matrix[ROWS][COLS + 1];

    printf("=== Test Case 1: Already Sorted Array (Non-Increasing) ===\n");
    fill_sorted_non_increasing(matrix, ROWS, COLS);
    printf("Before sorting:\n");
    print_matrix(matrix, ROWS, COLS);
    sort_matrix_rows_desc(matrix, ROWS, COLS);
    printf("After sorting:\n");
    print_matrix(matrix, ROWS, COLS);
    printf("\n");

    printf("=== Test Case 2: Unsorted Array (Random Numbers) ===\n");
    fill_random(matrix, ROWS, COLS);
    printf("Before sorting:\n");
    print_matrix(matrix, ROWS, COLS);
    sort_matrix_rows_desc(matrix, ROWS, COLS);
    printf("After sorting:\n");
    print_matrix(matrix, ROWS, COLS);
    printf("\n");

    printf("=== Test Case 3: Reverse-Sorted Array (Ascending) ===\n");
    fill_reverse_sorted(matrix, ROWS, COLS);
    printf("Before sorting:\n");
    print_matrix(matrix, ROWS, COLS);
    sort_matrix_rows_desc(matrix, ROWS, COLS);
    printf("After sorting:\n");
    print_matrix(matrix, ROWS, COLS);

    return 0;
}