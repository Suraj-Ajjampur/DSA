#include <stdio.h>

//Return the only non repeating element in an array where elements are repeated trice
int singleNumber(int* arr, int size){
    int ones = 0, twos = 0;

    int common_bitmask;
    for(int i=0;i<size;i++){
        twos = twos | (ones & arr[i]);
        ones = ones ^ arr[i];
        common_bitmask = ~(ones & twos);
        ones &= common_bitmask;
        twos &= common_bitmask;
    }
    return ones;
}


int main(){
    int array[] = {1,1,1,2,3,3,3};
    int size_arr = sizeof(array)/sizeof(array[0]);

    singleNumber(array, size_arr) == 2 ? printf("Pass\n") : printf("Fail\n");

    array[0] = 2; array[1] = 2;
    singleNumber(array, size_arr) == 1 ? printf("Pass\n") : printf("Fail\n");
    array[0] = 4; array[1] = 4; array[2] = 4;  
    singleNumber(array, size_arr) == 2 ? printf("Pass\n") : printf("Fail\n");
    
    return 0;
}