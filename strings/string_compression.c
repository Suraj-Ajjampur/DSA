
#include <stdio.h>
#include <string.h>

int compress(char* chars, int charsSize) {
    int writePos = 0; // Position to write the compressed character and its count.

    for (int i = 0; i < charsSize; i++) {
        chars[writePos++] = chars[i]; // Write the current character.
        int count = 1; // Initialize count of the current character.

        // Count occurrences of the current character.
        while (i + 1 < charsSize && chars[i] == chars[i + 1]) {
            i++;
            count++;
        }

        // If count is more than 1, convert it to a string and write each digit individually.
        if (count > 1) {
            // Convert count to string. This is an O(n) operation for each character.
            char countStr[12]; // Large enough to hold any int value.
            sprintf(countStr, "%d", count);
            
            // Write each digit of count to chars. This nested loop contributes to O(n^2) complexity.
            for (int j = 0; countStr[j] != '\0'; j++) {
                chars[writePos++] = countStr[j];
            }
        }
    }

    return writePos; // The new length of the compressed string.
}

int main() {
    // Example 1
    char example1[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result1 = compress(example1, sizeof(example1)/sizeof(example1[0]));
    printf("Example 1 - Result: %d, Expected: 6, String: %.*s\n", result1, result1, example1);
    if(result1 != 6 || strncmp(example1, "a2b2c3", result1) != 0) {
        printf("Example 1 failed\n");
    }

    // Example 2
    char example2[] = {'a'};
    int result2 = compress(example2, sizeof(example2)/sizeof(example2[0]));
    printf("Example 2 - Result: %d, Expected: 1, String: %.*s\n", result2, result2, example2);
    if(result2 != 1 || strncmp(example2, "a", result2) != 0) {
        printf("Example 2 failed\n");
    }

    // Example 3
    char example3[] = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int result3 = compress(example3, sizeof(example3)/sizeof(example3[0]));
    printf("Example 3 - Result: %d, Expected: 4, String: %.*s\n", result3, result3, example3);
    if(result3 != 4 || strncmp(example3, "ab12", result3) != 0) {
        printf("Example 3 failed\n");
    }

    return 0;
}