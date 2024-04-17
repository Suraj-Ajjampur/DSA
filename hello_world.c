#include <stdio.h>



void swap(int *x, int*y){
  int temp = *x;
  *x = *y;
  *y = temp;
}



// Write a program for quick sort
/**
 * @brief does something regarding pivot
*/
int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = low+1;
  for(int j =low; j<=high; j++){
    //if array element is lesser than the pivot element
    if(arr[j] < pivot){
      //Increment i and swap here
      i++;
      swap(&arr[j],&arr[i]);
    }
  }
  swap();
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


  quicksort(array, )
}

