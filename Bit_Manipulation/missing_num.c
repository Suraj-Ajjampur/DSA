#include<stdio.h>

int missingNumber(int* nums, int size){
    int XOR = 0;
    for(int i=0 ; i<size ;i++)
        XOR = XOR ^ nums[i];

    for(int i=0; i<=size; i++)
        XOR = XOR ^ i;
    
    return XOR;
}   

int main(){
    //Find the only number missing in an array given the range 0 to n

    int Array[] = {0,1,2,4,5};
    int size = sizeof(Array)/sizeof(Array[0]);

    missingNumber(Array,size) == 3 ? printf("Pass\n") : printf("Fail\n");
    
    return 0;
}