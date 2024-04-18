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
    //char* result = (char*)malloc((length+1)*sizeof(char));
    printf("The len is %d", length);
    fflush(stdout);
    //strcpy(result,str);
    for(int i =0, j =length-1; str[i]!= '\0' && i<j; i++,j--){
        swap(&str[i],&str[j]);
    }
}
int main(){

    char* string = "This is a string";
    reverse(string);
    printf("%s\n",string);
    //free(ans);
    return 0;
}