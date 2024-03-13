#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>
#include "array_operations.h"


int Binary_Seach(struct Array arr, int key){
    int l =0, h = arr.Length -1, mid;

    while(l<=h){
        mid = floor(h+l/2);

        if(key == arr.A[mid])
            return mid;

        else if(key > arr.A[mid])
            l = mid+1;
        
        else
            h = mid -1;
    }
    return -1;
}

void Reverse1(struct Array *arr){
    int *B;
    int i,j;

    B = (int *)malloc(sizeof(int)*arr->Length);
    for(i = arr->Length-1, j=0; i>=0; i--,j++){
        B[j] = arr->A[i];
    }
    //printf("Completed copying");
    for(i= 0;i<arr->Length;i++){
        arr->A[i] = B[i];
    }
    free(B);
}

/**
 * @brief Inserts element into a sorted array
 * 
 *
 * */
void Insert_into_Sorted_array(struct Array *arr, int x){
    int i=arr->Length-1;
    if(arr->Length == arr->Size)
        return;
    //Shift till A[i] > x
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->Length++;
}

int isSorted(struct Array arr){
    int i;
    for(i=0;i<arr.Length-1;i++){
        if(arr.A[i] > arr.A[i+1])
        return 0;
    }
    return 1;
}


void Rearrange(struct Array *arr){
    int i,j;
    i=0; //Used for finding -ve numbers
    //Used for finding +ve numbers
    j=arr->Length-1;
    while(i<j){
        while(arr->A[i]>=0)i++;
        while(arr->A[j]<0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}

/**
 * @brief  
**/
struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i=0,j=0,k=0;
    struct Array *ArrayMerged;
    ArrayMerged = (struct Array *)malloc(sizeof(struct Array));
    //compare and copy
    while(i < arr1->Length && j< arr2->Length){
        if(arr1->A[i]<arr2->A[j])
            ArrayMerged->A[k++] = arr1->A[i++];

        else
            ArrayMerged->A[k++] = arr2->A[j++];
    }
    //Copy the remaining elements from array 1 or 2
    for(;i<arr1->Length;i++)
        ArrayMerged->A[k++] = arr1->A[i]; 
    for(;j<arr2->Length;j++)
        ArrayMerged->A[k++] = arr2->A[j]; 
    
    ArrayMerged->Length = arr1->Length + arr2->Length;
    ArrayMerged->Size = 16;

    return ArrayMerged;
}

/**
 * @brief Copy elements from both arrays without copying the duplicates
 * more than once
*/
struct Array* Union(struct Array *arr1, struct Array *arr2){
    int i=0,j=0,k=0;
    struct Array *ArrayMerged;
    ArrayMerged = (struct Array *)malloc(sizeof(struct Array));
    //compare and copy
    while(i < arr1->Length && j< arr2->Length){
        if(arr1->A[i]<arr2->A[j])
            ArrayMerged->A[k++] = arr1->A[i++];

        else if(arr2->A[j] < arr1->A[i])
            ArrayMerged->A[k++] = arr2->A[j++];

        else{
            ArrayMerged->A[k++] = arr1->A[i++];
            j++;
        }
            
    }
    //Copy the remaining elements from array 1 or 2
    for(;i<arr1->Length;i++)
        ArrayMerged->A[k++] = arr1->A[i]; 
    for(;j<arr2->Length;j++)
        ArrayMerged->A[k++] = arr2->A[j]; 
    
    ArrayMerged->Length = k;
    ArrayMerged->Size = 16;

    return ArrayMerged;
}

/**
 * @brief Copy elements from both arrays without copying the duplicates
 * more than once
*/
struct Array* Intersection(struct Array *arr1, struct Array *arr2){
    int i=0,j=0,k=0;
    struct Array *ArrayMerged;
    ArrayMerged = (struct Array *)malloc(sizeof(struct Array));
    //compare and copy
    while(i < arr1->Length && j< arr2->Length){
        if(arr1->A[i]<arr2->A[j])
            i++;

        else if(arr2->A[j] < arr1->A[i])
            j++;

        else if(arr1->A[i]==arr2->A[j])
        {
            ArrayMerged->A[k++] = arr1->A[i++];
            j++; //Increment both 
        }
    }    
    ArrayMerged->Length = k;
    ArrayMerged->Size = 16;

    return ArrayMerged;
}

/**
 * @brief Displays elemets of an array
*/
void Display(struct Array arr){

    for(int i = 0;i < arr.Length; i++){
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

// void swap(int *x, int *y){
//     *x ^= *y;
//     *y = *y ^ *x;
//     *x ^= *y;
// }

void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

/**
 * @brief sorts the array
*/
int SelectionSort(struct Array *arr){

    int i,j,min_idx;

    // One by one move boundary of unsorted subarray
    for( i = 0; i < arr->Length-1; i++){
        // Find the min element in unsorted array
        min_idx = i;
        for(j=i+1; j < arr->Length; j++)
            if(arr->A[j] < arr->A[min_idx])
                min_idx = j;
            
        //Swap the found min element with the first element
        // of the unsorted sub array
        swap(&arr->A[min_idx], &arr->A[i]);
    }
}

int main()
{
    struct Array arr1={{1,2,3,4,5,6,7,8},10,8};
    struct Array arr2={{18,22,5,7,1,0,9,10},10,8};
    //Insert_element(&arr1,1,23);
    Display(arr2);
    //Delete_element(&arr1,5);
    SelectionSort(&arr2);
    Display(arr2);

   

    //int index = BinarySearch(&arr1,3);
    //printf("The element 8 is found at index %d\n",index);

    // struct Array *arr3;
    // printf("Output of merged array after set operation is \n");
    // //arr3=Merge(&arr1,&arr2);
    // //arr3=Union(&arr1,&arr2);
    // arr3=Intersection(&arr1,&arr2);
    // if (arr3 != NULL) {
    // Display(*arr3);
    // } else {
    //     printf("Intersection returned NULL.\n");
    // }

    // Rearrange(&arr1);

    // printf("%d\n",Binary_Seach(arr1,7));
    // printf("Is Sorted or not %d\n",isSorted(arr1));
    // Reverse1(&arr1);
    // Display(arr1);
    return 0;
}

