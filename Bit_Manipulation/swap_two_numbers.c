#include<stdio.h>


#define SWAP(x,y)  (((x) == (y)) || (((x) ^= (y)),((y) ^= (x)), ((x) ^= (y))))

void swap(int *x, int *y){
    if(*x == *y)
        return;
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
int main(){

    int x = 20, y =20;

    SWAP(x,y);

    printf("Value of x is %d, y = %d\n", x ,y);
    return 0;
}