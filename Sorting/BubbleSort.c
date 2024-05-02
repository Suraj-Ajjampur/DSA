#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int *arr,int len){
    int i, j;
    bool swapped;

    // i represents the numbers of passes
    for(i =0; i < len-1; i++){
        swapped = false;
        //
        for(j =0; j <len-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }       
        }
        //Check if no swaps where made by the inner loop
        if(swapped == false)
            break;
    }

}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    BubbleSort(arr,arr_size); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}