/**
 * @ref 1. https://www.geeksforgeeks.org/enumeration-enum-c/
 *      2. https://www.geeksforgeeks.org/typedef-in-c/
 *      3. https://www.geeksforgeeks.org/little-and-big-endian-mystery/
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int N = 3, M = 4;
int originalArray[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

// Topics enums, typedef, endianness
// To execute C, please define "int main()"
typedef enum{
  false,
  true
}bool;

bool isBigEndian();
int *rotate90_clockwise(int *array, int Rows, int Cols);
int *rotate90_anti_clockwise(int *array, int Rows, int Cols);
int *rotate180(int *array, int Rows, int Cols);

int main() {
  if(isBigEndian() == true)
    printf("Big Endian\n");
  else
    printf("Little endian\n");

    // Example test case: 3x4 array (N=3, M=4)


    // Convert 2D array to 1D array for passing to rotate90
    int* array = (int*)originalArray;

    // Rotate the array
    int* rotatedArray = rotate90_clockwise(array, N, M);
    int *rotatedAnticlockwise = rotate90_anti_clockwise(array,N,M);
    int *rotate180deg = rotate180(array,N,M);

    // Print the original array
    printf("Original Array:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", originalArray[i][j]);
        }
        printf("\n");
    }

    // Print the rotated array
    printf("\nRotated Array (90 degrees clockwise):\n");
    for (int i = 0; i < M; i++) { // Notice the swapped dimensions
        for (int j = 0; j < N; j++) {
            printf("%d ", rotatedArray[i*N + j]);
        }
        printf("\n");
    }

    // Print the rotated array
    printf("\nRotated Array (90 degrees anti-clockwise):\n");
    for (int i = 0; i < M; i++) { // Notice the swapped dimensions
        for (int j = 0; j < N; j++) {
            printf("%d ", rotatedAnticlockwise[i*N + j]);
        }
        printf("\n");
    }

    // Print the rotated array
    printf("\nRotated Array 180 degrees:\n");
    for (int i = 0; i < N; i++) { // Notice the swapped dimensions
        for (int j = 0; j < M; j++) {
            printf("%d ", rotate180deg[i*M + j]);
            fflush(stdout);
        }
        printf("\n");
    }

    // Free the rotated array to avoid memory leaks
    free(rotatedArray);
    free(rotatedAnticlockwise);
    free(rotate180deg);
  return 0;
}

//1. 
//use typedef to define the bool
//function to bytes in memory from location start to start+n
bool isBigEndian()
{
  bool res; //Random value assigned
  printf("Init val of typedef enum %d \n",res);

  unsigned int i = 1; //0x00 01 Big
                      //0x01 00 - Little
                      //0xAB CD
                      //0xCD AB //Little
                      //0xAB CD //Big endian representation
                      
  // a character pointer c is Since size of character is 1 byte when the character pointer 
  // is de-referenced it will contain only first byte of integer.pointing to an integer i. 
  char* c = (char *)&i;
  if(*c){
    res = false; // Little Endian
  }else{
    res = true; // Big Endian
  }
  return res;
}

//2. array[N*M], rotate the array by 90 degrees clockwise, N rows by M columns.
int *rotate90_clockwise(int *array, int Rows, int Cols) {
    int *rotatedArray = (int *)malloc(sizeof(int) * Rows * Cols);
    if(!rotatedArray) // Insufficient heap space
        return NULL;

    for (int originalRow = 0; originalRow < Rows; originalRow++) {
        for (int originalCol = 0; originalCol < Cols; originalCol++) {
            // New row index in rotated array is the original column index
            int newRow = originalCol;
            // New column index in rotated array is the reverse of the original row index
            int newCol = Rows - 1 - originalRow;
            
            // Calculating the new index for the element in the rotated array
            register int newIndex = newRow * Rows + newCol;
            
            // Original index of the element in the array before rotation
            register int originalIndex = originalRow * Cols + originalCol;
            
            // Assigning the element to its new position in the rotated array
            rotatedArray[newIndex] = array[originalIndex];
        }
    }
    return rotatedArray; // Return the newly rotated array
}

int *rotate90_anti_clockwise(int *array, int Rows, int Cols) {
    int *rotatedArray = (int *)malloc(sizeof(int) * Rows * Cols);
    if(!rotatedArray) // Insufficient heap space
        return NULL;

    for (int originalRow = 0; originalRow < Rows; originalRow++) {
        for (int originalCol = 0; originalCol < Cols; originalCol++) {
            // New row index in rotated array is the original column index
            int newRow = Cols - 1 - originalCol;
            // New column index in rotated array is the reverse of the original row index
            int newCol = originalRow;
            
            // Calculating the new index for the element in the rotated array
            register int newIndex = newRow * Rows + newCol;
            
            // Original index of the element in the array before rotation
            register int originalIndex = originalRow * Cols + originalCol;
            
            // Assigning the element to its new position in the rotated array
            rotatedArray[newIndex] = array[originalIndex];
        }
    }
    return rotatedArray; // Return the newly rotated array
}


int *rotate180(int *array, int Rows, int Cols) {
    int *rotatedArray = (int *)malloc(sizeof(int) * Rows * Cols);
    if(!rotatedArray) // Insufficient heap space
        return NULL;

    for (int originalRow = 0; originalRow < Rows; originalRow++) {
        for (int originalCol = 0; originalCol < Cols; originalCol++) {
            // New row index in rotated array is the original column index
            int newRow = Rows - 1 - originalRow;
            // New column index in rotated array is the reverse of the original row index
            int newCol = Cols - 1 - originalCol;
            
            // Calculating the new index for the element in the rotated array
            int newIndex = newRow * Cols + newCol;
            
            // Original index of the element in the array before rotation
            int originalIndex = originalRow * Cols + originalCol;
            
            // Assigning the element to its new position in the rotated array
            rotatedArray[newIndex] = array[originalIndex];
        }
    }
    return rotatedArray; // Return the newly rotated array
}
  

