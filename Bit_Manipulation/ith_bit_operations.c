#include <stdio.h>
#include <stdbool.h>


bool is_ith_bit_set(int num, int i){

    int bitmask = 1 << i;
    return (num & bitmask); 
}


//Write a program to set the ith bit of a number
//0 indexed
int set_ith_bit(int num, int i){

    int bitmask = 1<< i;
    return num |= bitmask;
}


//Write a program to clear the ith bit of a number
//0 indexed
int clear_ith_bit(int num, int i){

    int bitmask = 1<< i;
    return num &= ~(bitmask);
}

//Write a program to toggle the ith bit of a number
//0 indexed
int toggle_ith_bit(int num, int i){

    int bitmask = 1<< i;
    return num ^= bitmask;
}


int main(){
    //Driver code to test is_ith_bit_set
    is_ith_bit_set(1,0) == true ? printf("True\n") : printf("False\n"); //True
    is_ith_bit_set(5,2) == true ? printf("True\n") : printf("False\n"); //True
    is_ith_bit_set(5,1) == true ? printf("True\n") : printf("False\n"); //False

    //Driver code to test is_ith_bit_set
    set_ith_bit(0, 4) == 16 ? printf("Worked\n") : printf("Failed\n");
    set_ith_bit(0, 0) == 1 ? printf("Worked\n") : printf("Failed\n");
    set_ith_bit(5, 2) == 5 ? printf("Worked\n") : printf("Failed\n");

    //Driver code to test is_ith_bit_set
    clear_ith_bit(5,2) == 1 ? printf("Worked\n") : printf("Failed\n");
    clear_ith_bit(0,2) == 0 ? printf("Worked\n") : printf("Failed\n");
    clear_ith_bit(17,4) == 1 ? printf("Worked\n") : printf("Failed\n");

    //Driver code to test toggle_ith_bit
    toggle_ith_bit(5,2) == 1 ? printf("Worked\n") : printf("Failed\n");
    toggle_ith_bit(0,2) == 4 ? printf("Worked\n") : printf("Failed\n");
    toggle_ith_bit(17,4) == 1 ? printf("Worked\n") : printf("Failed\n");

    return 0;
}