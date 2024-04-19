// https://www.geeksforgeeks.org/bit-manipulation-swap-endianness-of-a-number/
//Write a function to check endianness of a system
#include<stdio.h>

//custom datatype bool
typedef enum{
    false,
    true
}bool;

bool check_for_endianness(){
    int n = 0x01;

    char *char_pointer = (char*)&n; //copies most significant byte

    printf("Storage of mutibyte data-types in this machine is - ");

    if(*char_pointer != 0)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");
};

// Function to swap a value from
// big Endian to little Endian and
// vice versa.
int swap_Endians(int value){

    int left_most_val = value & 0xFF000000;
    int left_middle_val = value & 0x00FF0000;
    int right_middle_val = value & 0x0000FF00;
    int right_most_val = value & 0x000000FF;

    left_most_val = left_most_val >> 24;
    left_middle_val = left_middle_val >> 8;
    right_middle_val = right_middle_val << 8;
    right_most_val = right_most_val << 24;

    int result = (left_most_val | left_middle_val |right_middle_val | right_most_val);
    return result;
}

// Litte Endian -> 01 00
// Big Endian -> 00 01
int main(){
    check_for_endianness();
    int big_endian = 0x12345678;
    int little_endian = 0x78563412;

    printf("Converted values 0x%x for big endians to little endian\n",swap_Endians(big_endian));
    printf("Converted values 0x%x for little endians to big endian\n",swap_Endians(little_endian));
    return 0;
}
