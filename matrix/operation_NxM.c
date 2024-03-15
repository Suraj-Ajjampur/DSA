#include <stdio.h>
#include <stdlib.h>

int** rotate90Clockwise(int** matrix, int rows, int cols, int* newRows, int* newCols) {
    *newRows = cols;
    *newCols = rows;
    int** rotated = (int**)malloc(*newRows * sizeof(int*));
    for (int i = 0; i < *newRows; i++) {
        rotated[i] = (int*)malloc(*newCols * sizeof(int));
        for (int j = 0; j < *newCols; j++) {
            rotated[i][j] = matrix[rows - 1 - j][i];
        }
    }
    return rotated;
}

int** rotate90AntiClockwise(int** matrix, int rows, int cols, int* newRows, int* newCols) {
    *newRows = cols;
    *newCols = rows;
    int** rotated = (int**)malloc(*newRows * sizeof(int*));
    for (int i = 0; i < *newRows; i++) {
        rotated[i] = (int*)malloc(*newCols * sizeof(int));
        for (int j = 0; j < *newCols; j++) {
            rotated[i][j] = matrix[j][cols - 1 - i];
        }
    }
    return rotated;
}

int** flipHorizontal(int** matrix, int rows, int cols) {
    int** flipped = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        flipped[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            flipped[i][j] = matrix[i][cols - 1 - j];
        }
    }
    return flipped;
}

int** flipVertical(int** matrix, int rows, int cols) {
    int** flipped = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        flipped[rows - 1 - i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            flipped[rows - 1 - i][j] = matrix[i][j];
        }
    }
    return flipped;
}

int** rotate180(int** matrix, int rows, int cols) {
    int** rotated = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        rotated[rows - 1 - i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            rotated[rows - 1 - i][cols - 1 - j] = matrix[i][j];
        }
    }
    return rotated;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 2, cols = 3;
    int newRows, newCols;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    int** rotatedClockwise = rotate90Clockwise(matrix, rows, cols, &newRows, &newCols);
    printf("\nRotated 90 Degrees Clockwise:\n");
    printMatrix(rotatedClockwise, newRows, newCols);

    int** rotatedAntiClockwise = rotate90AntiClockwise(matrix, rows, cols, &newRows, &newCols);
    printf("\nRotated 90 Degrees Anti-Clockwise:\n");
    printMatrix(rotatedAntiClockwise, newRows, newCols);

    int** flippedHor = flipHorizontal(matrix, rows, cols);
    printf("\nFlipped Horizontally:\n");
    printMatrix(flippedHor, rows, cols);

    int** flippedVert = flipVertical(matrix, rows, cols);
    printf("\nFlipped Vertically:\n");
    printMatrix(flippedVert, rows, cols);

    int** rotated180 = rotate180(matrix, rows, cols);
    printf("\nRotated 180 Degrees:\n");
    printMatrix(rotated180, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < newRows; i++) {
        free(rotatedClockwise[i]);
        free(rotatedAntiClockwise[i]);
    }
    free(rotatedClockwise);
    free(rotatedAntiClockwise);
    free(flippedHor);
    free(flippedVert);
    free(rotated180);

    return 0;
}

