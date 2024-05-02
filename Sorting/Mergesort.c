#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

//B {11, }
void Merge(int A[], int low, int mid, int high){

    int i,j,k;

    i = low; // 0
    j = mid+1; //1 
    k = low; //0

    // Create an aux array
    int *B = (int *)malloc(sizeof(int) * (high + 1 - low));
    //Copies the element to the aux array
    while(i <= mid && j <= high){
        //Which sub array is smaller
        if(A[i] < A[j]) //12  11
            B[k++] = A[i++];
        else
            B[k++] = A[j++];  // 11
    }
    // Remainig elements
    for(;i <= mid; i++)
        B[k++] = A[i];
    
    for(; j<=high;j++)
        B[k++] = A[j];

    //Copy the elements back from Aux array to the original array
    for(int z = low; z<= high;z++)
        A[z] = B[z];

    free(B);
}

void mergeSort(int arr[], int low, int high){
    int mid;
    if(low < high){
        mid = floor((low + high) /2); 

        mergeSort(arr,low,mid); // {13,15} 
        mergeSort(arr, mid+1,high); //{5, 6, 7}; // low = 3 high = 5 

        Merge(arr,low,mid,high);
    }
}


// { 12, 11, 13, 5, 6, 7 }; l = 0 , h = 5 , m = 2 // 1st call
// { 12, 11, 13}; l = 0 , h = 2 , m = 1 // 2nd call
// { 12, 11}; l = 0 , h = 1 , m = 0 // 3rd call
// {12}; l = 0 , h = 0 , m = 0 // 4th call
// {11}; l = 1 , h = 1 , m = 1 // 5th call
// Merge low =0, high =1 mid = 0
// {13}; l = 2 , h = 2 , m = 1 // 6th call
// Merge low =0, high = 2 mid = 1 {11,12,13}


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
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}