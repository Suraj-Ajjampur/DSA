#include <stdio.h>
#include <stdlib.h>

int global_Array[]={11,13,7,12,16,9,24,5,10,3};
int global_Array_2[]={15,14,29,12,16,9,24,5,10,3};

//Swap using temporary vairable
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

/**
 * @brief sorts the array
*/
int SelectionSort(int arr[],int array_length){

    int i,j,min_idx;

    // One by one move boundary of unsorted subarray
    for( i = 0; i < array_length-1; i++){
        // Find the min element in unsorted array
        min_idx = i;
        for(j=i+1; j < array_length; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;
            
        //Swap the found min element with the first element
        // of the unsorted sub array
        swap(&arr[min_idx], &arr[i]);
    }
}

int partition(int arr[],int low,int high)
{
  //choose the pivot as high element
   
  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}
 
// The Quicksort function Implemented
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot
    int pi=partition(arr,low,high);
     
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}


int main()
{
    int n=10,i;

    SelectionSort(global_Array_2, 10);
    quickSort(global_Array,0,n-1);
    //print out elements
    for(i=0;i<10;i++)
        printf("%d ",global_Array[i]);
    printf("\n");

    for(i=0;i<10;i++)
        printf("%d ",global_Array_2[i]);
    printf("\n");
    return 0;
}