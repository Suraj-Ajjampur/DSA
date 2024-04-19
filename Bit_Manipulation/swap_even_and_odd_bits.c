#include<stdio.h>

int swap_even_odd_bits(int n){  

    int even_bitmask = 0x55555555;//0,2,4,6 -> 0101
    int odd_bitmask = 0xAAAAAAAA; //1010
    
    //Fetch the bits from n
    even_bitmask &= n;
    odd_bitmask &= n;

    //Interchange even and odd
    even_bitmask <<=1;
    odd_bitmask  >>=1;

    return (even_bitmask | odd_bitmask);
}

int main(){
    swap_even_odd_bits(10) == 5 ? printf("Pass\n") : printf("Fail\n");
    swap_even_odd_bits(0) == 0 ? printf("Pass\n") : printf("Fail\n");
    swap_even_odd_bits(0xFF) == 0xFF ? printf("Pass\n") : printf("Fail\n");
    swap_even_odd_bits(0xAA) == 0x55 ? printf("Pass\n") : printf("Fail\n");
    return 0;
}