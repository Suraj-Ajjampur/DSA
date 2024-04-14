#include <stdio.h>
#include <stdbool.h>

#define NO_OF_CHARS 26

/**
 * @brief Check if two strings are anagrams of each other
 * @param str1 The first string to compare
 * @param str2 The second string to compare
 * @return true if the strings are anagrams, false otherwise
 *
 * This function checks whether two given strings are anagrams by comparing
 * the frequency of each character in the strings. It assumes that the input
 * strings are lowercase alphabets (a-z). The function uses two frequency arrays
 * to count the occurrence of each character in both strings. It first checks
 * if the strings are of the same length. If they are not, they cannot be anagrams.
 * Then, it compares the frequency arrays; if they match for every character,
 * the strings are anagrams.
 */
bool areAnagram(char* str1, char* str2)
{
    // Initialize count arrays for 26 English lowercase letters.
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};
    int i;

    // Iterate over each character in both strings simultaneously.
    for (i = 0; str1[i] && str2[i]; i++) {
        count1[str1[i] - 'a']++;  // Increment the count for the character in str1
        count2[str2[i] - 'a']++;  // Increment the count for the character in str2
    }

    // Check for string length mismatch. If one string ends before the other,
    // they cannot be anagrams.
    if (str1[i] || str2[i])
        return false;

    // Compare the character counts of both strings.
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count1[i] != count2[i])
            return false;

    return true;
}

/**
 * @brief Main function to test the areAnagram function.
 */
int main()
{
    char str1[] = "tommy";
    char str2[] = "momty";

    // Function call
    if (areAnagram(str1, str2))
        printf("The two strings are anagram of each other");
    else
        printf("The two strings are not anagram of each "
               "other");

    return 0;
}
