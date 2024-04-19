#include<stdio.h>
#include <stdlib.h>
#include<string.h>


int swap(char* x, char*y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(char* str){
    int length = strlen(str);
    for(int i =0, j =length-1; i<j; i++,j--){
        swap(&str[i],&str[j]);
    }
}


void reverse_call(char* begin, char *end){
    char temp;
    while(begin <end){
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

char* reverse_words_in_a_string(char* str){

    char* word_begin = str; 
    char *temp = str;
    // reverse every time there is a space
    while(*temp){ //run till *temp is NULL terminator
        temp++;
        if(*temp == '\0')
            reverse_call(word_begin, temp-1);

        else if(*temp == ' '){
            reverse_call(word_begin, temp-1);
            word_begin = temp+1; //word_begin at new word
        }
    }
    reverse_call(str, temp-1); //Reverse the whole string
    return str;
}

int main(){
    char string[] = "This is a string";
    printf("Original String is %s\n",string);
    //reverse(string);
    //printf("Reversed string is %s\n",string);
    
    printf("Reversed string is %s\n",reverse_words_in_a_string(string));
    //free(ans);
    return 0;
}