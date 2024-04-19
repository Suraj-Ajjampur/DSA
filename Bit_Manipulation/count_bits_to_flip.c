//Count the number of bits to be flipped to convert A to B

#include<stdio.h>

int bits_to_be_flipped(int A, int B){
    //compute the XOR of A and B

    int temp = A^B;
    //Count the number of set bits
    int count =0;

    //Brian Kernighan's algo
    while(temp !=0){
        temp &= temp-1;
        count++; 
    }
    return count;
}

int main(){
    int A = 10, B = 0xF;

    bits_to_be_flipped(A,B) == 2 ? printf("Pass\n") : printf("Fail\n");
    bits_to_be_flipped(0,0) == 0 ? printf("Pass\n") : printf("Fail\n");
    bits_to_be_flipped(0xFF,1) == 7 ? printf("Pass\n") : printf("Fail\n");
    return 0;
}