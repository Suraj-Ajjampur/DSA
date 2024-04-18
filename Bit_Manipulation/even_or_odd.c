#include <stdio.h>

//Find whether a number is even or odd
void even_or_odd(int num){

    if(num & 1 == 1)
        printf("%d is odd \n", num);
    else    
        printf("%d is even \n", num);
}

int main(){

    even_or_odd(0);
    even_or_odd(1);
    even_or_odd(5);
    even_or_odd(80);
    even_or_odd(2001);
    even_or_odd(505050);


    //Write driver code to test for negative numbers
    even_or_odd(-53);
    even_or_odd(-2);
    even_or_odd(-8);
    even_or_odd(-22);
    even_or_odd(-5);
    return 0;
}