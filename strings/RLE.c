#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 101 // Since the constraints say the string length is at most 100

int cache[MAX_SIZE][MAX_SIZE][MAX_SIZE]; // Cache for memoization
int count[MAX_SIZE]; // To store the count of each character's appearance in sequence

int getLengthOfOptimalCompression(char* s, int k) {
    // Helper function to calculate the length of encoding
    int countRLE(int len, int count) {
        if (count == 1) return 1; // Single character
        if (count < 10) return 2; // One digit
        if (count < 100) return 3; // Two digits
        return 4; // Three digits
    }

    // Recursive function to find the solution
    int solve(int i, int k, int prev, int prev_cnt) {
        if (k < 0) return INT_MAX / 2; // Simulating infinity
        if (i == strlen(s)) return 0;

        // Check the cache
        if (cache[i][k][prev_cnt] != -1) return cache[i][k][prev_cnt];

        int result;
        if (s[i] == prev) {
            // Increase count if same as previous
            result = countRLE(i, prev_cnt + 1) - countRLE(i, prev_cnt) + solve(i + 1, k, prev, prev_cnt + 1);
        } else {
            // Try deleting this character or start a new sequence
            int deleteChar = solve(i + 1, k - 1, prev, prev_cnt);
            int keepChar = countRLE(i, 1) + solve(i + 1, k, s[i], 1);
            result = deleteChar < keepChar ? deleteChar : keepChar;
        }

        // Save to cache
        cache[i][k][prev_cnt] = result;
        return result;
    }

    // Initialize cache with -1
    memset(cache, -1, sizeof(cache));
    memset(count, 0, sizeof(count));
    // Call the recursive solve function
    return solve(0, k, 0, 0);
}

int main() {
    char s[] = "aaabcccd";
    int k = 2;
    printf("Minimum length of the run-length encoded version: %d\n", getLengthOfOptimalCompression(s, k));
    return 0;
}
