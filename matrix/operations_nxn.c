#include<stdio.h>
#include<stdlib.h>

void rotate90_anticlockwise(int** matrix, int matrixSize);
void rotate180(int** matrix, int matrixSize);
void flip_horizontal(int** matrix, int matrixSize);
void flip_vertical(int** matrix, int matrixSize);
void rotate(int** matrix, int matrixSize);

int main() {
    int n = 3; // Assuming a 3x3 matrix for simplicity
    int* matrix[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * n + j + 1; // Fill the matrix
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    
    // Perform and print transformations
    rotate180(matrix, n);
    printf("\nRotated 180 degrees:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Perform and print transformations
    rotate(matrix, n);
    printf("\nRotated 90 degrees clockwise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Perform and print transformations
    rotate90_anticlockwise(matrix, n);
    printf("\nRotated 90 degrees anticlockwise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    flip_horizontal(matrix, n);
    printf("\nHorizontally flipped matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    flip_vertical(matrix, n);
    printf("\nVertically flipped matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Reset or fill the matrix again for each new transformation if necessary
    // Repeat the above steps for rotate180, flip_horizontal, and flip_vertical

    for (int i = 0; i < n; i++) {
        free(matrix[i]); // Free the allocated memory
    }

    return 0;
}

/**
 * Rotates a given n x n 2D matrix by 90 degrees clockwise in place.
 * 
 * @param matrix The 2D matrix to be rotated.
 * @param matrixSize The size of the matrix (number of rows, which is equal to the number of columns).
 * @param matrixColSize Array containing the size of each column (not used since the matrix is n x n).
 */
void rotate(int** matrix, int matrixSize) {
    // Step 1: Transpose the matrix
    for (int r = 0; r < matrixSize; r++) {
        for (int c = r; c < matrixSize; c++) {
            // Swap elements to transpose the matrix
            int temp = matrix[r][c];
            matrix[r][c] = matrix[c][r];
            matrix[c][r] = temp;
        }
    }
    /* 1 2 3    1 4 7   7 4 1
       4 5 6 -> 2 5 8 ->8 5 2
       7 8 9    3 6 9   9 6 3
   */

    // Step 2: Flip the matrix horizontally
    for (int r = 0; r < matrixSize; r++) {
        for (int c = 0; c < matrixSize / 2; c++) {
            // Swap elements to flip the matrix horizontally
            int temp = matrix[r][c];
            //printf("swapping element %d\n", matrix[r][c]);
            matrix[r][c] = matrix[r][matrixSize - 1 - c];
            matrix[r][matrixSize - 1 - c] = temp;
        }
    }
}

void rotate90_anticlockwise(int** matrix, int matrixSize) {
    // First transpose the matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // Then flip it vertically
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = 0; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - i][j];
            matrix[matrixSize - 1 - i][j] = temp;
        }
    }
}

void rotate180(int** matrix, int matrixSize) {
    int temp;
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = 0; j < matrixSize; j++) {
            // Swap the element with its opposite element
            temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - i][matrixSize - 1 - j];
            matrix[matrixSize - 1 - i][matrixSize - 1 - j] = temp;
        }
    }

    // If the matrix size is odd, flip the middle row
    if (matrixSize % 2 == 1) {
        int middle = matrixSize / 2;
        for (int j = 0; j < matrixSize / 2; j++) {
            temp = matrix[middle][j];
            matrix[middle][j] = matrix[middle][matrixSize - 1 - j];
            matrix[middle][matrixSize - 1 - j] = temp;
        }
    }
}


void flip_horizontal(int** matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = temp;
        }
    }
}

void flip_vertical(int** matrix, int matrixSize) {
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = 0; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - i][j];
            matrix[matrixSize - 1 - i][j] = temp;
        }
    }
}
