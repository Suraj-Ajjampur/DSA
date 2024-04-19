

#include<stdio.h>


int odd_occ_number(int *arr, int len){

    int result =0;
    for(int i=0;i<len;i++){
        result ^= arr[i];
    }
    return result;
}

int main(){
    int array[] = {1,1,1,2,2,3,3};
    int len = sizeof(array)/sizeof(array[0]);
    odd_occ_number(array, len) == 1 ? printf("Pass\n") : printf("Fail\n");
    array[0] = 2;
    odd_occ_number(array, len) == 2 ? printf("Pass\n") : printf("Fail\n");
    array[0] = 3; 
    odd_occ_number(array, len) == 3 ? printf("Pass\n") : printf("Fail\n");
    return 0;
}