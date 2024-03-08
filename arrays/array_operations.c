#include "array_operations.h"

/**
 * @brief Displays elemets of an array
*/
void Display(struct Array arr){

    for(int i = 0;i < arr.Length; i++){
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

/**
 * @brief Inserts an element into the array 
*/
void Insert_element(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index <=arr->Length)
    {
        for(i=arr->Length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->Length++;
    }
}

/**
 * @brief Deletes an element from the array
*/
int Delete_element(struct Array* s, int index){

    int x = s->A[index];
    for(int i = index; i<s->Length;i++){
        s->A[i] = s->A[i+1]; 
    }
    s->Length--;
    return x;
}

/**
 * @brief deletes all occurances of a particular value from the array
 * 
**/
// int Delete_val(struct Array *s, int val){
//     int x = s->A[];
// }

void swap(int *x, int *y){
    *x ^= *y;
    *y = *y ^ *x;
    *x ^= *y;
}

/**
 * @brief searches for key in array 
 *        moves found element to front to improve time complexity
 * 
 * @return index if found
 *         -1 if not found
*/
int LinearSearch(struct Array *arr, int key){
    int i;
    for(i=0 ; i < arr->Length ; i++){
        if(key == arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
    return -1; //Key not found
}


/**
 * @brief searches for key in array using binary search
 * 
 * @return index if found
 *         -1 if not found
*/
int BinarySearch(struct Array *arr, int key){
    int l,h,mid;
    l = 0;
    h=arr->Length-1;

    while(l<=h){
        mid = (l+h/2);

        if(key == arr->A[mid])
            return mid;
        
        else if(key < arr->A[mid])
            h = mid-1;
        
        else //key > arr->A[mid]
            l = mid+1;
    }
    return -1; //key not found
}