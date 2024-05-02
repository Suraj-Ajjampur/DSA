#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void SelectionSort(int *arr,int n){
    int i, j, min_index;

    //Push the boundary of the unsorted array
    for(i =0; i < n-1; i++){
        min_index = i;
        for(j = i+1; j < n; j++)
            if(arr[j] < arr[min_index])
                min_index = j;
        
        //Swap the min_index position with i
        swap(&arr[i], &arr[min_index]);
    }
}
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
  
    SelectionSort(arr, arr_size); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}

