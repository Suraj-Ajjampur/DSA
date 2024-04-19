#include <stdio.h>

//Return the non repeating element in the array
int singleNumber(int* nums, int numsSize) {
    //Constant Extra space is array
    int result = 0;
    
    for(int i =0; i<numsSize; i++){
        result  ^= nums[i];
    }
    return result;
}


int main(){


    int array[] = {1,1,2,3,3};
    int size_arr = sizeof(array)/sizeof(array[0]);

    singleNumber(array, size_arr) == 2 ? printf("Pass\n") : printf("Fail\n");
    return 0;
}