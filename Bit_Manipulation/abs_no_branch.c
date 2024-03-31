/**
 * @ref https://graphics.stanford.edu/~seander/bithacks.html#IntegerAbs
 * 
 */ 
#include <stdio.h>
#include <limits.h>

// Function to compute absolute value without branching
unsigned int abs_no_branch(int v) {
    //isolates the sign bit of the integer v.
    int const mask = v >> (sizeof(int) * CHAR_BIT - 1); 
    // Original method
    // unsigned int r = (v + mask) ^ mask;
    // Patented variation
    unsigned int r = (v ^ mask) - mask;
    return r;
}

int main() {
    // Test cases
    int testValues[] = {0, 1, -1, INT_MAX, INT_MIN};
    int numTests = sizeof(testValues) / sizeof(testValues[0]);

    for (int i = 0; i < numTests; i++) {
        int value = testValues[i];
        unsigned int absValue = abs_no_branch(value);
        printf("The absolute value of %d is %u.\n", value, absValue);
    }

    return 0;
}
