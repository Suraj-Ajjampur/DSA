#include<stdio.h>

// Remove the last set bit of a number

int remove_last_set_bit(int n){
    
    if(n == 0)
        return n;

    //1100 & 1011
    return n &= (n-1);
}

int main(){

    remove_last_set_bit(5) == 4 ? printf("Worked\n") : printf("Failed\n");
    remove_last_set_bit(8) == 0 ? printf("Worked\n") : printf("Failed\n");
    remove_last_set_bit(16) == 0 ? printf("Worked\n") : printf("Failed\n");
    remove_last_set_bit(3) == 2 ? printf("Worked\n") : printf("Failed\n");
    remove_last_set_bit(10) == 8 ? printf("Worked\n") : printf("Failed\n");
    remove_last_set_bit(0) == 0 ? printf("Worked\n") : printf("Failed\n");

    return 0;
}