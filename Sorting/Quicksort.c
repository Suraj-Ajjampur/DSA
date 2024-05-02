#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

//              i
//                      m  
//int arr[] = { 13, 12, 11, 5, 6, 7 };  

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int low, int high){

    int i,j;
    int pivot = arr[low]; //12

    //Holds the index of the pivot element
    i = high+1; // i = 4
    for(j = i -1; j>low;j--){ //j =2
        if(arr[j] >= pivot){
            i--;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i-1], &arr[low]);
    return i-1;
}
// { 12, 11, 13, 5, 6, 7 }; l = 0 , h = 5 // 1st call
// { 12, 11, 13}; l = 0 , h = 2 , m = 1 // 2nd call
// { 12, 11}; l = 0 , h = 1 , m = 0 // 3rd call
// {12}; l = 0 , h = 0 , m = 0 // 4th call
// {11}; l = 1 , h = 1 , m = 1 // 5th call
// Merge low =0, high =1 mid = 0
// {13}; l = 2 , h = 2 , m = 1 // 6th call
// Merge low =0, high = 2 mid = 1 {11,12,13}




void QuickSort(int * array, int low, int high){
    if(low <high){
        
        //Pass in the array and get the correct position of the pivot index
        //After this array is sorted wrt pi
        int pi = partition(array,low, high); // 1

        //Sort the array left of the pivot
        QuickSort(array, low, pi -1); //  2 , 2
        QuickSort(array, pi+1, high); // 3 , 3
    }
}

// UTILITY FUNCTIONS 
// Function to print an array 
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    QuickSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}
