//https://yuminlee2.medium.com/leetcode-48-rotate-image-973d0e85ffc6

#include <stdio.h>

/**
 * Rotates a given n x n 2D matrix by 90 degrees clockwise in place.
 * 
 * @param matrix The 2D matrix to be rotated.
 * @param matrixSize The size of the matrix (number of rows, which is equal to the number of columns).
 * @param matrixColSize Array containing the size of each column (not used since the matrix is n x n).
 */
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    // Step 1: Transpose the matrix
    for (int r = 0; r < matrixSize; r++) {
        for (int c = r; c < matrixSize; c++) {
            // Swap elements to transpose the matrix
            int temp = matrix[r][c];
            matrix[r][c] = matrix[c][r];
            matrix[c][r] = temp;
        }
    }

    // Step 2: Flip the matrix horizontally
    for (int r = 0; r < matrixSize; r++) {
        for (int c = 0; c < matrixSize / 2; c++) {
            // Swap elements to flip the matrix horizontally
            int temp = matrix[r][c];
            matrix[r][c] = matrix[r][matrixSize - 1 - c];
            matrix[r][matrixSize - 1 - c] = temp;
        }
    }
}

// Function to print the matrix
void printMatrix(int** matrix, int matrixSize) {
    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixSize = 3;
    int* matrix[3];
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};
    matrix[0] = row1;
    matrix[1] = row2;
    matrix[2] = row3;

    // Print the original matrix
    printf("Original matrix:\n");
    printMatrix(matrix, matrixSize);

    // Rotate the matrix 90 degrees clockwise
    rotate(matrix, matrixSize, NULL); // NULL for matrixColSize as it's not used in this case

    // Print the rotated matrix
    printf("\nRotated matrix by 90 degrees clockwise:\n");
    printMatrix(matrix, matrixSize);

    return 0;
}