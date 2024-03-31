#include <stdio.h>
#include <limits.h> // For CHAR_BIT

void sign_extend_variable(int x, unsigned b) {
    int r; // Resulting sign-extended number

    // Ensure x only contains b bits (if necessary)
    x = x & ((1U << b) - 1);
    
    // Sign extend
    int const m = 1U << (b - 1);
    r = (x ^ m) - m;
    
    printf("Variable bit-width: %d (extended from %u bits)\n", r, b);
}

void sign_extend_constant(int x) {
    unsigned b = 5; // Example constant bit-width
    int r; // Resulting sign-extended number
    
    // Faster method for constant bit-widths
    int const m = CHAR_BIT * sizeof(x) - b;
    r = (x << m) >> m;
    
    printf("Constant bit-width: %d (extended from %u bits)\n", r, b);
}

int main() {
    int x = -3; // Example number

    // Sign extend from a variable bit-width (e.g., 5 bits)
    sign_extend_variable(x, 5);

    // Sign extend assuming constant bit-width
    sign_extend_constant(x);

    return 0;
}
