#include<stdio.h>

int main(void){
    int x = 20;
    int y = 10;

    int max = x^((x^y) & -(x < y)); //max(x,y)
    int min = y^((x^y) & -(x < y));

    printf("The maximum number is %d\n", max);
    printf("The minimum number is %d\n", min);
}

