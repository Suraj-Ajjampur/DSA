/**
 * @brief Given a set of strings, find the longest common prefix.
 * 
 * @ref https://www.geeksforgeeks.org/stdstrncmp-in-c/
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the longest common prefix string amongst an array of strings.
char* longestCommonPrefix(char* arr[], int n) {
    if (n == 0) return "-1";

    // Dynamically allocate memory for the result to safely modify it.
    char* result = (char*)malloc(strlen(arr[0]) + 1);
    if (result == NULL) return "-1";  // Check for memory allocation failure.
    strcpy(result, arr[0]);

    for (int i = 1; i < n; i++) {
        int len = strlen(result);
        // Reduce the length of the prefix until a match is found or result is empty.
        while (strncmp(arr[i], result, len) != 0) {
            result[--len] = '\0'; // Shorten the result and null terminate.

            if (len == 0) {  // If nothing left, free the memory and return no common prefix.
                free(result);
                return "-1";
            }
        }
    }
    return result;
}

// Driver function to test the longestCommonPrefix function
int main() {
    char* input[] = { "geeksforgeeks", "geeks", "geek", "geezer" };
    int n = sizeof(input) / sizeof(input[0]);

    char* lcp = longestCommonPrefix(input, n);
    if (strcmp(lcp, "-1") != 0) {
        printf("The longest Common Prefix is: %s\n", lcp);
    } else {
        printf("No common prefix.\n");
    }
    free(lcp); // Free the allocated memory.
    return 0;
}
