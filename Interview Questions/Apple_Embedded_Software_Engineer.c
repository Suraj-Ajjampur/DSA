/**
 * @ref 1. https://www.geeksforgeeks.org/enumeration-enum-c/
 *      2. https://www.geeksforgeeks.org/typedef-in-c/
 *      3. https://www.geeksforgeeks.org/little-and-big-endian-mystery/
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// Topics enums, typedef, endianness
// To execute C, please define "int main()"
typedef enum{
  false,
  true
}bool;

bool isBigEndian();
int *rotate90(int *array, int N, int M);

int main() {
  if(isBigEndian() == true)
    printf("Big Endian\n");
  else
    printf("Little endian\n");

    // Example test case: 3x4 array (N=3, M=4)
    int N = 3, M = 4;
    int originalArray[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Convert 2D array to 1D array for passing to rotate90
    int* array = (int*)originalArray;

    // Rotate the array
    int* rotatedArray = rotate90(array, N, M);

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

    // Free the rotated array to avoid memory leaks
    free(rotatedArray);
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

int *rotate90(int *array, int N, int M)
{
  int *rotatedArray = (int *)malloc(sizeof(int) * N * M);
  if(! rotatedArray) return NULL;

    //A[0,1,2,3] 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Calculate the new position for the current element
            // 0 * 1 + (1 - 1 - 0) = Newindex
            int newIndex = j * N + (N - 1 - i); 
            // Copy the element to its new position
            rotatedArray[newIndex] = array[i * M + j];
        }
    }

    return rotatedArray; // Return the new array

}
//Transpose the array
  

