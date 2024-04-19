#include<stdio.h>


char upper_to_lower_case(char ch){
    return (char)(ch | ' ');
}

char lower_to_upper_case(char ch){
    return (char)(ch & '_');
}

char invert_case(char ch){
    return (char)(ch ^ ' ');
}

int letter_pos_in_alphabet(char ch){
    return (int)(ch & 31);
}

int main(){

    printf("A in lower case is %c\n",upper_to_lower_case('A'));
    printf("a in upper case is %c\n",lower_to_upper_case('a'));
    printf("a in case inverted is %c\n",invert_case('a'));
    printf("D position in the alphabet is %d\n",letter_pos_in_alphabet('D'));

    return 0;
}
