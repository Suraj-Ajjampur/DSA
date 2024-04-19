//Copy set bits in a range

//Toggle set bits in a range
#include <stdio.h>

int copy_set_bits_in_range(int A, int B, int L, int R){

    //Copy the bits of B to A for a given range
    int bitmask = ((1ll << (R+1))-1) & ~((1 << L) -1);

    B &= bitmask; //Fetch only bits L to R

    //Clear those same bits in A
    A &= ~(bitmask);

    A |= B;

    return A;
}

int toggle_bits_in_range(int A, int L, int R){
    int bitmask = ((1ll <<(R+1)) -1) & ~((1 << L)-1);
    
    return (A^bitmask); 
}

int main(){
    
    copy_set_bits_in_range(10, 0xF, 2, 4) == 0xE ? printf("Pass\n"): printf("Fail\n"); // 1010 | 1111 -> 1110
    copy_set_bits_in_range(0, 0xFF, 3, 4) == 0x18 ? printf("Pass\n"): printf("Fail\n"); //  0000 0000 | 1111 1111 -> 0001 1000
    copy_set_bits_in_range(0xFF, 0xFF, 3, 4) == 0xFF ? printf("Pass\n"): printf("Fail\n"); // 1010 | 1111 -> 1110

    // Additional corner cases
    copy_set_bits_in_range(0, 0, 0, 31) == 0 ? printf("Pass\n"): printf("Fail\n"); // Edge case: both A and B are 0
    copy_set_bits_in_range(0xFFFFFFFF, 0x0, 0, 31) == 0 ? printf("Pass\n"): printf("Fail\n"); // Edge case: A is all 1s, B is all 0s, should clear A
    copy_set_bits_in_range(0xFFFFFFFF, 0xFFFFFFFF, 0, 31) == 0xFFFFFFFF ? printf("Pass\n"): printf("Fail\n"); // Edge case: both A and B are all 1s
    copy_set_bits_in_range(0xAAAAAAAA, 0x55555555, 0, 31) == 0x55555555 ? printf("Pass\n"): printf("Fail\n"); // Edge case: A and B are alternating bits, B should overwrite A
    copy_set_bits_in_range(0x12345678, 0x87654321, 0, 0) == 0x12345679 ? printf("Pass\n"): printf("Fail\n"); // Edge case: Range starts and ends at 0, no change

    printf("Start the toggle\n");
    toggle_bits_in_range(0, 2, 4) ==  0x1C ? printf("Pass\n"): printf("Fail\n"); // 0000 ^ 0001 1100
    toggle_bits_in_range(0xFF, 0, 2) ==  0xF8 ? printf("Pass\n"): printf("Fail\n"); // 1111 1111 -> 0000 0111 -> 1111 1000

    return 0;
}