/**
 * @brief function to check for anagram 
*/

#include<stdio.h>
#include<string.h>

typedef enum{
    false,
    true
}bool;


#define NO_OF_CHARS 26

bool Anagrams(char* str1, char* str2){

    if(strlen(str1) != strlen(str2))
        return false;

    //2 freq arrays
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};

    int i;

    //Run a for loop here and increment the freq array index
    for(i=0; str1[i] && str2[i]; i++){
        count1[str1[i] - 'a']++;
        count2[str2[i] - 'a']++;
    }

    //Run a for loop checking the elements of the freq array
    for(i=0; i < NO_OF_CHARS; i++){
       if(count1[i] != count2[i])
            return false;
    }
    return true;
}

int main(){
    char* str1 = "tommy";
    char* str2 = "momty";

    if(Anagrams(str1,str2) == true){
        printf("These 2 strings are anagrams of each other");
    }
    else    
        printf("Not anagrams");

    return 0;
}