#include<stdio.h>

//Swap the ith and Jth bit.
// 0 indexed
int swap(int num, int i, int j){

    //fetch ith and jth bit 
    int bitmask_i = num & (1 << i);
    int bitmask_j = num & (1 << j);

    //Clear ith and jth bit 
    num &= ~(1 <<i);
    num &= ~(1 <<j);
    //Assign ith and jth bit to each other
    num |= (bitmask_i >> i) << j;
    num |= (bitmask_j >> j) << i;

    return num;
}

int main(){

    swap(10, 0,1) == 9 ? printf("Pass\n") : printf("Fail");
    swap(0xFF, 5,6) == 0xFF ? printf("Pass\n") : printf("Fail");
    swap(0, 0,10) == 0 ? printf("Pass\n") : printf("Fail");
    swap(0x07, 1,3) == 0x0D ? printf("Pass\n") : printf("Fail"); //0111 -> 1101 

    
    return 0;
}