#include <stdint.h>
#include <stdio.h>

uint32_t countSetBits(uint32_t n) {
    uint32_t count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

//Question - He simply gave me this function and told me to solve it
uint32_t bitmapCountSetInRange(uint32_t *map, uint32_t mapSize, uint32_t rangeStart, uint32_t rangeLength) {
    uint32_t count = 0;
    uint32_t startIndex = rangeStart / 32;
    uint32_t endIndex = (rangeStart + rangeLength - 1) / 32;
    uint32_t startBit = rangeStart % 32;
    uint32_t endBit = (rangeStart + rangeLength - 1) % 32;

    // Special handling for the case where the range is within a single integer
    if (startIndex == endIndex) {
        for (uint32_t bit = startBit; bit <= endBit; ++bit) {
            if (map[startIndex] & (1 << bit)) {
                count++;
            }
        }
    } else {
        // Process the first part
        if (startBit != 0) {
            uint32_t firstPartMask = ~((1 << startBit) - 1);
            count += countSetBits(map[startIndex] & firstPartMask);
            startIndex++;
        }

        // Process whole integers in the middle
        for (uint32_t i = startIndex; i < endIndex; ++i) {
            count += countSetBits(map[i]);
        }

        // Process the last pat
        if (endBit != 31) {
            uint32_t lastPartMask = (1 << (endBit + 1)) - 1;
            count += countSetBits(map[endIndex] & lastPartMask);
        } else { // If endBit is 31, then we process the entire integer
            count += countSetBits(map[endIndex]);
        }
    }

    return count;
}

int main() {
    uint32_t m1[] = {0x00000001, 0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA};
    printf("Test Case 1: %u\n", bitmapCountSetInRange(m1, 128, 32, 32)); // Expected output: 30

    uint32_t m2[] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
    printf("Test Case 2: %u\n", bitmapCountSetInRange(m2, 128, 0, 128)); // Expected output: 128

    uint32_t m3[] = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA};
    printf("Test Case 3: %u\n", bitmapCountSetInRange(m3, 128, 0, 128)); // Expected output: 64

    uint32_t m4[] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000};
    printf("Test Case 4: %u\n", bitmapCountSetInRange(m4, 128, 96, 32)); // Expected output: 0

    uint32_t m5[] = {0x00000000, 0x00000000, 0x00000000, 0x00000001};
    printf("Test Case 5: %u\n", bitmapCountSetInRange(m5, 128, 127, 1)); // Expected output: 1

    return 0;
}