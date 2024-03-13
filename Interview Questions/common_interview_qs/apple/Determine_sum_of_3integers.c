//https://www.educative.io/blog/apple-coding-interview-questions

#include<stdio.h>
#include<stdbool.h>

//Problem statement: Given an array of integers and a value, 
//determine if there are any three integers in the array whose sum equals the given value.


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Selection_Sort(int *arr, int arr_length){

    
    //printf("Length of the array is %d\n", arr_length);

    int i,j,min_idx;

    for(i = 0; i <arr_length -1; i++){

        min_idx =i;
        for(j =i+1; j<arr_length; j++){
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

int Display(int *arr, int length){

    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


bool find_sum_of_two(int *arr, int val, size_t start_index, int arr_length){
    for(int i = start_index, j = arr_length - 1; i<j;){
        int sum = arr[i] + arr[j];
        if (sum == val) 
            return true;

        else if(sum < val)
            ++i;

        else 
            --j;
    }
    return false;
}
/**
 * @brief first sort the array, fix one element and find a pair(a,b) in 
 * the remaining array so that a+b = required_sum - e;
 * 
 * If we find the pair, we have found the solution: a, b and e. We stop iteration
 * 
 * Otherwise, we repeat the above steps for all elements e at index i = 1 to n - 3 
 * until we find a pair that meets the condition.
*/
bool find_sum_of_three(int *arr, int required_sum, int arr_length) {
    //First sort the array
    Selection_Sort(arr,arr_length);
    Display(arr,arr_length);

    for(int i=0; i<arr_length-2; ++i){
        int remaining_sum = required_sum - arr[i];
        if(find_sum_of_two(arr,remaining_sum,i+1,arr_length))
            return true;
    }
    
    return false;
}

int main(void){

    int arr[] = {3,7,1,2,8,4,5};
    int arr_length = sizeof(arr) / sizeof(arr[0]);

    Display(arr,arr_length);

    if(find_sum_of_three(arr,16,arr_length))
        printf("True\n");
    else    
        printf("False\n");

    return 0;   
}