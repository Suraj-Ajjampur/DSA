#include <stdio.h>



void swap(int *x, int*y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

/**
 * @brief 
 */

void SelectSort(int arr[], int arr_size){
  int i,j,min_idx = 0;
  
  for(int i = 0; i< arr_size -1; i++){
    min_idx = i;
    for(int j=i+1; j <=arr_size-1;j++){
      if(arr[j] < arr[min_idx])
        min_idx = j;
    }
    swap(&arr[i], &arr[min_idx]);
  }
}

// Write a program for quick sort
/**
 * @brief does something regarding pivot
*/
int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = low-1;
  for(int j =low; j<=high; j++){
    //if array element is lesser than the pivot element
    if(arr[j] < pivot){
      //Increment i and swap here
      i++;
      swap(&arr[j],&arr[i]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return i +1;
}

void quickSort(int arr[], int low, int high){
  if(low <high){
    //Define a partition index
    int pi = partition(arr, low, high);

    //Recurive call to quick sort to subarray before pi and after pi
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}


int main() {
  int array[] ={2,5,2,1,2,3,4,5};
  int size = sizeof(array)/sizeof(array[0]);

  quickSort(array, 0, size-1);
  
  printf("Sorted Array\n");
  for(int i=0;i<size;i++){
    printf("%d ", array[i]);
  }
  return 0;
}

