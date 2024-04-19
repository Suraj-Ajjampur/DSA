#include<stdio.h>
#include<stdint.h>

uint32_t reverseBits(uint32_t num){
    uint32_t ans =0;

    for(int i = 0; i<32; i++){
        ans <<= 1;
        ans |= (num & 1);
        num >>= 1;
    }

    return ans;
}


int main() {
    uint32_t test1 = 0b00000000000000000000000010101010; // Sample input in binary format
    uint32_t test2 = 0xFFFFFFFF; // Edge case: all bits are 1
    uint32_t test3 = 0x80000000; // Edge case: only the MSB is 1
    uint32_t test4 = 0x00000001; // Edge case: only the LSB is 1
    uint32_t test5 = 0xAAAAAAAA; // Pattern input: alternating bits

    // Perform the bit reversal and print the results
    printf("Reversed bits of test1: %u\n", reverseBits(test1));
    printf("Reversed bits of test2: 0x%x\n", reverseBits(test2));
    printf("Reversed bits of test3: %u\n", reverseBits(test3));
    printf("Reversed bits of test4: 0x%x\n", reverseBits(test4));
    printf("Reversed bits of test5: 0x%x\n", reverseBits(test5));

    return 0;
}
