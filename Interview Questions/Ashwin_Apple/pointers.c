/**
 * @def describes the 4 decalations
 * Int *p[10];      -> array of integer pointers
 * Int (*p)[10];    -> Pointer to an array of 10 integers
 * Int (*p)[10]();  -> function pointer that takes no arguements and returns an int[10] (array of 10 integers)
 * Int (*p[])();    -> array of pointers to functions, where each function pointed to takes unspecified arguments and returns an int
*/

#include <stdio.h>

// Function that returns a static array of 10 integers.
int* getStaticArray() {
    static int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    return arr;
}

// Function to demonstrate pointer to a function returning pointer to an array of integers.
int* (*getArrayFunction())() {
    return getStaticArray;
}

int main() {
    int *ptrArray[10]; // Array of integer pointers
    int (*arrayPtr)[10]; // Pointer to an array of 10 integers
    int (*functionPtr)(); // Pointer to function returning pointer to an array of integers

    functionPtr = getStaticArray;
    arrayPtr = &ptrArray; // This is conceptually incorrect but demonstrates the type

    // Example of calling a function via a pointer that returns a pointer to an array
    int *arr = functionPtr();
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
