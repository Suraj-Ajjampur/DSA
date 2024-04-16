/** 
 * @brief Check if 2 strings are a palindrome of each other
 * 
 * 
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char* str){

    int len = strlen(str);

    char reverse[len+1];
    int i;

    for(i = 0; str[i] !='\0'; i++){
        reverse[i] = str[--len];
    }
    reverse[i+1] = '\0'; //Add NULL terminator here

    printf("Reversed string is %s\n",reverse);

    if(strcmp(reverse,str) == 0)
        return true;
    else    
        return false;

}

int main(){
    char* str = "level";
    if(isPalindrome(str) == true)
        printf("%s is a palindrome\n", str);
    
    else
        printf("%s is not a palindrome\n", str);
}