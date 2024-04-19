#include <stdio.h>
#include <limits.h>

#define BRIAN_KERNIGHAN


// Write a function to count the number of set bits in a number
int count_set_bits(int num){
    int count =0;
    while(num !=0){
        if(num & 1) //Regular way
            count++; //Count
        num = num >> 1; //Right shift number
    }
    return count;
}
//Above function uses O(log(n)) - Time complexity

// Time complexty O(1)
int Brian_Kernighan(int num){
    int count =0;
    while(num !=0){
        //Clear the rightmost set bit everytime, until N becomes 0
        num &= (num-1);
        count++;
    }
    return count;
}

//  1010
// &1001

//Driver code to test number of set bits
int main(void){
    
    count_set_bits(8) == 1 ? printf("Pass\n") : printf("Fail\n");
    count_set_bits(0) == 0 ? printf("Pass\n") : printf("Fail\n");
    count_set_bits(10) == 2 ? printf("Pass\n") : printf("Fail\n");
    count_set_bits(11) == 3 ? printf("Pass\n") : printf("Fail\n");
    count_set_bits(0xF) == 4 ? printf("Pass\n") : printf("Fail\n");

    Brian_Kernighan(8) == 1 ? printf("Pass\n") : printf("Fail\n");
    Brian_Kernighan(0) == 0 ? printf("Pass\n") : printf("Fail\n");
    Brian_Kernighan(10) == 2 ? printf("Pass\n") : printf("Fail\n");
    Brian_Kernighan(11) == 3 ? printf("Pass\n") : printf("Fail\n");
    Brian_Kernighan(0xF) == 4 ? printf("Pass\n") : printf("Fail\n");

    return 0;
}