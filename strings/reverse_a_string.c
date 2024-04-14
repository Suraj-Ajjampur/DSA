#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Reverses a sequence of characters within a string.
 * @param begin Pointer to the first character in the sequence to be reversed.
 * @param end Pointer to the last character in the sequence to be reversed.
 *
 * This function takes two pointers, indicating the start and end of a sequence
 * within a string, and reverses the sequence in-place.
 */
void reverse(char* begin, char* end){
    char temp;
    while(begin < end){
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/**
 * @brief Reverses the words in a given string.
 * @param str Pointer to the string whose words are to be reversed.
 * @return Returns the pointer to the string with words reversed.
 *
 * This function processes a string by reversing each word individually first
 * and then reversing the entire string to put the words in the reverse order.
 * A word is defined as a sequence of characters separated by spaces.
 */
char* reverseWords(char* str){
    char* word_begin = str; // Pointer to the beginning of a word
    char* temp = str;       // Temporary pointer for traversal

    // Traverse the string
    while(*temp){
        temp++;
        if(*temp == '\0'){
            reverse(word_begin, temp - 1); // Reverse the last word
        }
        else if(*temp == ' '){
            reverse(word_begin, temp - 1); // Reverse the current word
            word_begin = temp + 1;         // Move to the next word
        }
    }

    // Reverse the entire string to achieve the final order
    reverse(str, temp - 1);
    return str;
}

// Driver code
int main()
{
    char s[] = "i like this program very much";
    reverseWords(s);
    printf("%s\n", s);
    return 0;
}
