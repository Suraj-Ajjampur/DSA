#include <stdio.h>

//
#define MASK_LOWER(x) ((x) & 0x00FF)
#define MASK_HIGHER(x) ((x) & 0xFF00)
#define CHANGE_POS(x) ((MASK_LOWER(x) << 8) | (MASK_HIGHER(x) >> 8))

int main(){
    unsigned int num = 0xAABB;
    unsigned int result = CHANGE_POS(num);
    
    printf("0x%X\n", result); // Use hexadecimal format specifier
}
