#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* begin, char* end){
    char temp;
    while(begin < end){
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

char* reverse_string(char* str){

    char *res = (char*)malloc(strlen(str)+1);
    strcpy(res, str);

    char* word_begin = res; // Pointer to the beginning of a word
    char* temp = res;       // Temporary pointer for traversal

    // Traverse the string
    while(*temp){
        temp++; //incrementing the pointer
        if(*temp == '\0'){
             reverse(word_begin, temp - 1); // Reverse the last word
        }
        else if(*temp == ' '){
            reverse(word_begin, temp - 1);
            //move to next word
            word_begin = temp + 1;
        }
    }
    //Reverse the entire string to achieve the final order
    reverse(res,temp - 1);
    return res;
}

int main(){
    
    char s[] = " i like this program very much";
    printf("%s\n",reverse_string(s));
    return 0;

}